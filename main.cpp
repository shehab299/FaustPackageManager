#include <curl/curl.h>
#include <iostream>
#include <string>
#include <regex>
#include "pkgUrl/PkgUrl.h"
#include "pkgUrl/PkgUrlExcption.h"

int main(int argc, char const *argv[])
{

    while(true){
        std::string url;
        std::cin >> url;

        try
        {
            PkgUrl locater(url);
            std::cout << locater.getAuthor() << std::endl;
            std::cout << locater.getLibraryName() << std::endl;
            std::cout << locater.getVersion() << std::endl;
        }
        catch(const PkgUrlExcption& e)
        {
            std::cout << e.what() << std::endl;
        }    
    }
    
    return 0;
}
