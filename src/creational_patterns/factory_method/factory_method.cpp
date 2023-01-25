#include <string>

// Product
#include "parser_intf.h"

// Concrete Products 
#include "map_parser.h"
#include "par_parser.h"
#include "json_parser.h"

// Concrete Creator or Client
std::unique_ptr<cParser> createParser(std::unique_ptr<cParser>& pParserFactory) 
{ 
    return pParserFactory->create();
}

void printInvalidFile()
{
    std::cerr << "Input is not valid. Please provide path to a '*.json', '*.map', '*.par' configuration file!" << std::endl;
    return;
}

int main() 
{

    std::string strFileName = {""};

    std::cout << std::endl;
    std::cout << "Please type in path to a configuration file: " << std::endl;
    std::cin >> strFileName;

    const size_t nPos = strFileName.find_last_of(".");
    if(!nPos)
    {
        printInvalidFile();
    }

    const std::string strFileType = strFileName.substr(nPos);
    
    std::unique_ptr<cParser> pParserFactory = {nullptr};

    if(!strFileType.compare(".map"))
    {
        pParserFactory = std::make_unique<cMapParser>();
    }
    else if(!strFileType.compare(".par"))
    {
        pParserFactory = std::make_unique<cParParser>();
    }
    else if (!strFileType.compare(".json"))
    {
        pParserFactory = std::make_unique<cJsonParser>();
    }
    else
    {
        printInvalidFile();
        return 0;
    }

    const auto pConcreteParser = createParser(pParserFactory);
    const auto oMeasurementConfig = pConcreteParser->parse_file(strFileName);

    std::cout << "The Config inherits " << oMeasurementConfig.size() << " methods" << std::endl << std::endl;
    for(const auto& oMethod : oMeasurementConfig)
    {
        std::cout << oMethod.first << ":" << std::endl;
        for(const auto& oSignal : oMethod.second)
        {
            std::cout << "  " << oSignal << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}