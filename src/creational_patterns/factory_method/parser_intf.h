#pragma once
#include <memory>
#include <iostream>

class cParser
{ 
 public: 
    virtual std::unique_ptr<cParser> create() 
    { 
        std::cout << "Create Parser" << std::endl;
        return std::make_unique<cParser>();
    }
    virtual void parse_file(std::string strFileName)
    {
        std::cout << "cParser - Parsing configuration file: " << strFileName.c_str() << std::endl;
    }
};