#include "Registry.h"
#include "../PkgUrl/PkgUrl.h"
#include <iostream>
#include <filesystem>
#include <stdexcept>

Registry::Registry(){
}


std::string Registry::getPkgPath(std::string pkgUrl)
{
    PkgUrl pkg(pkgUrl);
    std::string baseDir = "./libraries/" + pkg.getLibraryName();
    std::string versionDir = baseDir + "/" + pkg.getVersion();
    std::string path = versionDir + "/" + pkg.getLibraryName();

    if (std::filesystem::exists(path)) {
        return path;
    }

    try {
        std::filesystem::create_directories(versionDir);
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to create directories: " + std::string(e.what()));
    }

    downloader.download("shehab299", "Registry", "main/" + pkg.getPath(), path);

    return path;
}
