#pragma once
#include "parser_intf.h"
#include "../../../3rdparty/pugixml/src/pugixml.hpp"

class cMapParser: public cParser 
{
    std::unique_ptr<cParser> create() override;
    void parse_file(std::string strFileName) override;
    void handle_outputs_nodes(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes);
};