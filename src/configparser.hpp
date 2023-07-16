#ifndef CONFIGPARSER__HPP
#define CONFIGPARSER__HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "configparser.cpp"

#pragma once

class ConfigParser
{
private:
    std::string configPath;
public:
    bool configOpen = false;
    ConfigParser(const std::string &configPath);
    ~ConfigParser();
};


ConfigParser::ConfigParser(const std::string &configPath)
{
    ConfigParser::configPath = configPath;
    std::ifstream file(configPath);
    if (!file.good())
        std::cerr << "Config Parser: Config file not found: \n" + configPath + "\n";
    else
        configOpen = true;
}

ConfigParser::~ConfigParser()
{
}
#endif