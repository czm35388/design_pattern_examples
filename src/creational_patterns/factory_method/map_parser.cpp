#include "map_parser.h"

std::unique_ptr<cParser> cMapParser::create() 
{ 
    return std::make_unique<cMapParser>();
}

void cMapParser::parse_file(std::string strFileName)
{
    std::cout << "Mapfile - Parser parse configuration file: " << strFileName.c_str() << std::endl;

    pugi::xml_document oMapfile;
    pugi::xml_parse_result result = oMapfile.load_file(strFileName.c_str());

    if (!result)
    {
        std::cerr << "XML parsing failed! Error description: " << result.description() << std::endl;
    }
    else
    {
        std::cout << "XML parsing of mapfile succeeded!" << std::endl;
    }

    handle_outputs_nodes(oMapfile.children("output"));
}

void cMapParser::handle_outputs_nodes(pugi::xml_object_range<pugi::xml_named_node_iterator> output_nodes)
{
    uint16_t nOutputNodeCount = { 0 }; 
    for(const auto output_node : output_nodes)
    {
        nOutputNodeCount += 1;
    }

    std::cout << "Number of OutputNodes: " << nOutputNodeCount << std::endl;
}
