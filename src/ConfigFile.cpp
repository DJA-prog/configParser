#include "ConfigParser.hpp"

namespace ConfigFileNamespace
{
    ConfigFile::ConfigFile(std::string filename) : filename(filename)
    {
        readFile();
    }

    ConfigFile::~ConfigFile()
    {
        // No need to check if the file is open here
        file.close();
    }

    bool ConfigFile::fileExists(const std::string &filePath)
    {
        std::ifstream file(filePath);
        return file.good();
    }

    bool ConfigFile::save()
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            bool firstLine = true;
            for (auto &section : sections)
            {
                if (!firstLine)
                    file << '\n';
                else
                    firstLine = false;
                    
                file << "[" << section.first << "]" << std::endl;
                for (auto &setting : section.second)
                {
                    file << setting.first << "=" << setting.second << std::endl;
                }
            }
            if (file.fail())
            {
                std::cout << "Error: Failed to write to file " << filename << "." << std::endl;
                return false;
            }
            file.close();
            return true;
        }
        else
        {
            std::cerr << "Unable to open file " << filename << " for saving" << std::endl;
            return false;
        }
    }

    void ConfigFile::readFile()
    {
        file.open(filename);
        std::string line;
        std::string currentSection = "";
        while (std::getline(file, line))
        {
            // Check if line is a section header
            if (line[0] == '[')
            {
                currentSection = line.substr(1, line.size() - 2);
            }
            else if (line.find("=") != std::string::npos)
            {
                std::string key = line.substr(0, line.find("="));
                std::string value = line.substr(line.find("=") + 1);
                sections[currentSection][key] = value;
            }
        }
        file.close();
    }

    bool ConfigFile::sectionExists(const std::string &section)
    {
        return sections.count(section) != 0;
    }

    bool ConfigFile::settingExists(std::string section, std::string setting)
    {
        if (sectionExists(section))
        {
            return sections[section].find(setting) != sections[section].end();
        }
        return false;
    }

    std::string ConfigFile::getString(const std::string &section, const std::string &setting)
    {
        // Check if the section exists
        if (sections.count(section) == 0)
        {
            std::cout << "Error: Section '" << section << "' does not exist" << std::endl;
            return "";
        }

        // Check if the setting exists
        if (sections[section].count(setting) == 0)
        {
            std::cout << "Error: Setting '" << setting << "' does not exist in section '" << section << "'" << std::endl;
            return "";
        }

        // Return the value of the setting
        return sections[section][setting];
    }

    int ConfigFile::getInt(std::string section, std::string option, int defaultValue)
    {
        try
        {
            return std::stoi(getString(section, option));
        }
        catch (std::exception &e)
        {
            return defaultValue;
        }
    }

    float ConfigFile::getFloat(std::string section, std::string option, float defaultValue)
    {
        try
        {
            return std::stof(getString(section, option));
        }
        catch (std::exception &e)
        {
            return defaultValue;
        }
    }

    bool ConfigFile::getBool(const std::string &section, const std::string &option)
    {
        std::string value = getString(section, option);
        std::istringstream iss(value);
        bool b;
        iss >> std::boolalpha >> b;
        return b;
    }

    bool ConfigFile::updateSetting(std::string section, std::string key, std::string value)
    {
        if (!sectionExists(section))
            return false;
        sections[section][key] = value;
        return save();
    }

    bool ConfigFile::updateSection(std::string name, std::map<std::string, std::string> values)
    {
        if (!sectionExists(name))
            return false;
        sections[name] = values;
        return save();
    }

    bool ConfigFile::appendSection(std::string name, std::map<std::string, std::string> values)
    {
        if (sectionExists(name))
            return false;
        sections[name] = values;
        return save();
    }

    bool ConfigFile::insertOption(std::string section, std::string key, std::string value)
    {
        if (!sectionExists(section))
            return false;
        sections[section][key] = value;
        return save();
    }

    void ConfigFile::createSection(std::string sectionName)
    {
        if (!sectionExists(sectionName))
        {
            std::ofstream file(filename, std::ios::app);
            if (file.good())
            {
                file << "[" << sectionName << "]" << std::endl;
                file.close();
            }
            else
            {
                std::cout << "Error creating section " << sectionName << std::endl;
            }
        }
    }

    bool ConfigFile::deleteSection(std::string sectionName)
    {
        if (sectionExists(sectionName))
        {
            sections.erase(sectionName);
            return save();
        }
        return false;
    }

    bool ConfigFile::deleteSetting(const std::string &sectionName,const std::string &setting)
    {
        if (sectionExists(sectionName))
        {
            // Check if the setting exists
            if (!settingExists(sectionName, setting))
            {
                std::cout << "Error: Setting '" << setting << "' does not exist in section '" << sectionName << "'" << std::endl;
                return false;
            }
            else
            {
                sections[sectionName].erase(setting);
                return save();
            }
        }
        return false;
    }
}
