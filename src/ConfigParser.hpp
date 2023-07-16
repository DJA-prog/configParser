#ifndef CONFIGPARSER__HPP
#define CONFIGPARSER__HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <ctime>
#include <sstream>

namespace ConfigFileNamespace
{
    class ConfigFile
    {
    private:
        std::string filename;
        std::time_t lastRead;
        std::map<std::string, std::string> settings;
        std::ifstream file;

    public:
        // All configs are in here to be altered before use or write
        std::map<std::string, std::map<std::string, std::string>> sections;

        void readFile();
        bool fileExists(const std::string &filePath);
        bool save();

        bool sectionExists(const std::string &section);
        bool settingExists(std::string section, std::string setting);
        bool updateSetting(std::string section, std::string key, std::string value);
        bool updateSection(std::string name, std::map<std::string, std::string> values);
        bool appendSection(std::string name, std::map<std::string, std::string> values);
        bool insertOption(std::string section, std::string key, std::string value);
        void createSection(std::string sectionName);

        bool deleteSection(std::string sectionName);
        bool deleteSetting(const std::string &sectionName, const std::string &setting);

        // Get methods
        bool getBool(const std::string &section, const std::string &option);
        std::string getString(const std::string &section, const std::string &setting);
        int getInt(std::string section, std::string option, int defaultValue = 0);
        float getFloat(std::string section, std::string option, float defaultValue = 0.0);

        ConfigFile(std::string filename);
        ~ConfigFile();
    };
}

class ConfigParser
{
private:
    std::string configPath;
    ConfigFileNamespace::ConfigFile *configFile;

public:
    bool configOpen = false;
    ConfigParser(const std::string &configPath);
    ~ConfigParser();

    std::string getSetting(const std::string &section, const std::string &key, const std::string &defaultValue = "");
    std::map<std::string, std::string> getSection(const std::string &section);
    void updateSetting(const std::string &section, const std::string &key, const std::string &value);
    void updateSection(const std::string &section, const std::map<std::string, std::string> &values);
    bool deleteSection(const std::string &section);
    bool deleteSetting(const std::string &section, const std::string &setting);
};

#endif
