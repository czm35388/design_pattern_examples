#include "par_parser.h"

std::unique_ptr<cParser> cParParser::create()
{ 
    return std::make_unique<cParParser>();
}
void cParParser::parse_file(std::string strFileName)
{
    std::cout << "Parfile - Parser parse configuration file: " << strFileName.c_str() << std::endl;
    std::cout << "Parfile - parsing not yet implemented!" << std::endl;
}
