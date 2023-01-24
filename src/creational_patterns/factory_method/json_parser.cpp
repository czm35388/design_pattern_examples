#include "json_parser.h"
#include <fstream>

using json = nlohmann::json;

std::unique_ptr<cParser> cJsonParser::create()
{
    return std::make_unique<cJsonParser>();
}

void cJsonParser::parse_file(std::string strFileName)
{
    std::cout << "JSON - Parser parse configuration file: " << strFileName.c_str() << std::endl;
    std::ifstream ifs(strFileName, std::ifstream::in);

    json oJsonConfig = {};

    try
    {
        oJsonConfig = json::parse(ifs);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "JSON parsing succeeded!" << std::endl;
}
