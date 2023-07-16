#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../examples/example.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
        // Create the "home" section
        std::map<std::string, std::string> homeValues;
        homeValues["rooms"] = "8";
        homeValues["floor"] = "tiles";
        homeValues["roof"] = "triangle metal";
        homeValues["doors"] = "9";
        homeValues["windows"] = "12";
        config.updateSection("home", homeValues);
    }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
