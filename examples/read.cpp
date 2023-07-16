#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../examples/example.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
        // Read values from sections
        std::cout << "Print Section:" << std::endl;
        std::cout << "Lable: " << config.getSetting("print", "lable") << std::endl;
        std::cout << "Version: " << config.getSetting("print", "version") << std::endl;
        std::cout << "Ink: " << config.getSetting("print", "ink") << std::endl;
        std::cout << "Address: " << config.getSetting("print", "addr") << std::endl;
        std::cout << "Manufacturer: " << config.getSetting("print", "manufacturer") << std::endl;
        std::cout << "Port: " << config.getSetting("print", "port") << std::endl;

    }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
