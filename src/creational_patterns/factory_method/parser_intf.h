#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

typedef std::map<std::string, std::vector<std::string>> config_storage;

class cParser
{ 
 public: 
    virtual std::unique_ptr<cParser> create() 
    { 
        std::cout << "Create Parser" << std::endl;
        return std::make_unique<cParser>();
    }
    virtual config_storage parse_file(std::string strFileName)
    {
        std::cout << "cParser - Parsing configuration file: " << strFileName.c_str() << std::endl;
        return config_storage();
    }
};