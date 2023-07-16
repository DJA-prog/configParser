#include "../src/ConfigParser.hpp"
#include <iostream>

int main()
{
    std::string configPath = "../examples/example.conf";
    ConfigParser config(configPath);

    if (config.configOpen)
    {
    }
    else
    {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
    }

    return 0;
}
