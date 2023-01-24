#include <string>

// Product
#include "parser_intf.h"

// Concrete Products 
#include "map_parser.h"
#include "par_parser.h"
#include "json_parser.h"

// Concrete Creator or Client
std::unique_ptr<cParser> createParser(std::unique_ptr<cParser>& pParser) 
{ 
    return pParser->create();
}

int main() 
{

    std::string strFileName = {""};

    std::cout << std::endl;
    std::cout << "Please type in path to a configuration file: " << std::endl;
    std::cin >> strFileName;

    const size_t nPos = strFileName.find_last_of(".");
    const std::string strFileType = strFileName.substr(nPos);
    
    std::unique_ptr<cParser> pParser = {nullptr};

    if(!strFileType.compare(".map"))
    {
        pParser = std::make_unique<cMapParser>();
    }
    else if(!strFileType.compare(".par"))
    {
        pParser = std::make_unique<cParParser>();
    }
    else if (!strFileType.compare(".json"))
    {
        pParser = std::make_unique<cJsonParser>();
    }
    else
    {
        std::cerr << "Input is not valid. Please provide path to a '.map' or '.par' configuration file!" << std::endl;
    }

    const auto pParserImpl = createParser(pParser);
    pParserImpl->parse_file(strFileName);

    std::cout << std::endl;
}