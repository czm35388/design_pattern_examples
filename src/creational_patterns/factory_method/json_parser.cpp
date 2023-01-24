#include "json_parser.h"

std::unique_ptr<cParser> cJsonParser::create()
{
    std::cout << "Create Json-Parser" << std::endl;
    return std::unique_ptr<cParser>();
}

void cJsonParser::parse_file(std::string strFileName)
{
    std::cout << "Json - Parser parse configuration file: " << strFileName.c_str() << std::endl;

    
}
