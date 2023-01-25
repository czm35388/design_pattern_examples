#include "json_parser.h"
#include <fstream>

using json = nlohmann::json;
static constexpr char strJsonErrPrefix[] = {"JSON file isn't valid: \n"};

std::unique_ptr<cParser> cJsonParser::create()
{
    return std::make_unique<cJsonParser>();
}

config_storage cJsonParser::parse_file(std::string strFileName)
{
    std::cout << "JSON - Parser parse configuration file: " << strFileName.c_str() << std::endl << std::endl;
    std::ifstream oFileStream(strFileName, std::ifstream::in);

    json oJsonConfig = {};

    try
    {
        oJsonConfig = json::parse(oFileStream);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    if(!oJsonConfig.find("measurement_ui_config").value().size())
    {
        std::cerr << strJsonErrPrefix << "No 'measurment_ui_config' found!" << std::endl;
    }
    if(!oJsonConfig.find("measurement_ui_config").value().is_array())
    {
        std::cerr << strJsonErrPrefix << "'measurement_ui_config' object isn't an array!" << std::endl;
    }

    config_storage oMeasurmentConfig = {};
    for(const auto& oMethod : oJsonConfig["measurement_ui_config"])
    {
        std::vector<std::string> oSignals = {};
        for(const auto& oSignal : oMethod["signals"])
        {
            oSignals.push_back(oSignal);
        }
        oMeasurmentConfig.insert(std::pair{oMethod["name"], oSignals});
    }

    return oMeasurmentConfig;
}