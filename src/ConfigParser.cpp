#include "ConfigParser.hpp"
#include "ConfigFile.cpp"

ConfigParser::ConfigParser(const std::string &configPath)
{
    configFile = new ConfigFileNamespace::ConfigFile(configPath);
    configOpen = configFile->fileExists(configPath);
}

ConfigParser::~ConfigParser()
{
    delete configFile;
}

std::string ConfigParser::getSetting(const std::string &section, const std::string &key, const std::string &defaultValue)
{
    if (configFile->sectionExists(section))
    {
        if (configFile->settingExists(section, key))
        {
            return configFile->getString(section, key);
        }
    }
    return defaultValue;
}

std::map<std::string, std::string> ConfigParser::getSection(const std::string &section)
{
    if (configFile->sectionExists(section))
    {
        return configFile->sections[section];
    }
    return std::map<std::string, std::string>();
}

void ConfigParser::updateSetting(const std::string &section, const std::string &key, const std::string &value)
{
    if (configFile->sectionExists(section))
    {
        configFile->updateSetting(section, key, value);
    }
    else
    {
        std::map<std::string, std::string> values;
        values[key] = value;
        configFile->appendSection(section, values);
    }
}

void ConfigParser::updateSection(const std::string &section, const std::map<std::string, std::string> &values)
{
    if (configFile->sectionExists(section))
    {
        configFile->updateSection(section, values);
    }
    else
    {
        configFile->appendSection(section, values);
    }
}

bool ConfigParser::deleteSection(const std::string &section)
{
    if (configFile->sectionExists(section))
    {
        return configFile->deleteSection(section);
    }
    return false;
}

bool ConfigParser::deleteSetting(const std::string &section, const std::string &setting)
{
    if (configFile->sectionExists(section))
    {
        if (configFile->settingExists(section, setting))
        {
            return configFile->deleteSetting(section, setting);
        }
        return false;
    }
    return false;
}