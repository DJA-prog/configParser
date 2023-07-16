#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../tests/test.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
        // Read values from sections
        std::cout << "Print Section:" << std::endl;
        std::cout << "Label: " << config.getSetting("print", "label") << std::endl;
        std::cout << "Version: " << config.getSetting("print", "version") << std::endl;
        std::cout << "Ink: " << config.getSetting("print", "ink") << std::endl;
        std::cout << "Address: " << config.getSetting("print", "addr") << std::endl;
        std::cout << "Manufacturer: " << config.getSetting("print", "manufacturer") << std::endl;
        std::cout << "Port: " << config.getSetting("print", "port") << std::endl;

        std::cout << "\nLAN Section:" << std::endl;
        std::cout << "Gate: " << config.getSetting("lan", "gate") << std::endl;
        std::cout << "Address: " << config.getSetting("lan", "addr") << std::endl;

        // Update the "location" section with random data
        std::map<std::string, std::string> locationValues;
        locationValues["city"] = "YR8sCLnB";
        locationValues["country"] = "y3fjWbF0op";
        config.updateSection("location", locationValues);

        // Update the "location" section with random data
        std::map<std::string, std::string> PlanetValues;
        PlanetValues["sun"] = "none";
        PlanetValues["count"] = "12";
        PlanetValues["water"] = "true";
        config.updateSection("planets", PlanetValues);
    }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
