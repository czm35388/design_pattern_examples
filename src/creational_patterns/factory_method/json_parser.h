#pragma once

#include "parser_intf.h"
#include "../../../3rdparty/nlohmann_json/include/json.hpp"

class cJsonParser: public cParser 
{
    std::unique_ptr<cParser> create() override;
    config_storage parse_file(std::string strFileName) override;
};