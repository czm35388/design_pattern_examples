#pragma once
#include "parser_intf.h"

// Concrete Products 
class cParParser: public cParser 
{
    std::unique_ptr<cParser> create() override;
    config_storage parse_file(std::string strFileName) override;
};