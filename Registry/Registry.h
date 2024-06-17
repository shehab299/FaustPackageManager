#pragma once

#include "Registry.h"
#include "../Downloader/GithubDownloader.h"
#include <string>

class Registry{

    private:
        GithubDownloader downloader;
        
    public:
        Registry();
        std::string getPkgPath(std::string pkgUrl);
};


