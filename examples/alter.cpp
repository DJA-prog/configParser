#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../examples/example.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
        // Update the "location" section with random data
        std::map<std::string, std::string> homeValues;
        homeValues["rooms"] = "5";
        homeValues["floor"] = "carpet";
        homeValues["roof"] = "flat metal";
        homeValues["doors"] = "6";
        homeValues["windows"] = "7";
        config.updateSection("home", homeValues);
    }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
