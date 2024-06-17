#include <iostream>
#include <string>
#include "Registry/Registry.h"

int main(int argc, char const *argv[])
{

    while(true){
        std::string url;

        std::cout << "Enter the url of the package: ";
        std::cin >> url;

        Registry registry;

        try
        {
            std::string path = registry.getPkgPath(url);
            std::cout << "The package path is: " << path << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return 0;
}
