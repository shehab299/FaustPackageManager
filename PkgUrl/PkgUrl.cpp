#include "PkgUrl.h"
#include <regex>
#include "PkgUrlExcption.h"

PkgUrl::PkgUrl(std::string url)
{
    parse(url);
}

void PkgUrl::parse(std::string url)
{

    using namespace std::regex_constants; 

    std::regex pattern("^pkg:faust(?:/([_a-zA-Z]\\w*))?/([_a-zA-Z]\\w*.lib)@((?:\\d+)(?:\\.(?:\\d+)(?:\\.(?:\\d+))?)?)$", icase | ECMAScript); 

    std::smatch locater_parts;
    
    if(!std::regex_search(url,locater_parts,pattern))
        throw PkgUrlExcption("Package Locater Not Is Valid");

    this->author = locater_parts[1].str();
    this->libName = locater_parts[2].str();
    this->version = locater_parts[3].str();
}

std::string PkgUrl::getAuthor() const{
    return this->author;
}


std::string PkgUrl::getLibraryName() const{
    return this->libName;
}


std::string PkgUrl::getVersion() const {
    return this->version;
}