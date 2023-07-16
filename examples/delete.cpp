#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../examples/example.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
        if (config.deleteSection("print"))
            std::cout << "Deleted section: print" << std::endl;
        else
            std::cout << "Could not delete section: print" << std::endl;

        if (config.deleteSetting("server", "ports"))
            std::cout << "Deleted section: server , setting: ports" << std::endl;
        else
            std::cout << "Could not delete section: server , setting: ports" << std::endl;
        }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
