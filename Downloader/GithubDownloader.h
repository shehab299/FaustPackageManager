#pragma once
#include <string>
#include <curl/curl.h>

class GithubDownloader{

private:
    CURL* handle;

    static size_t write_data(void* ptr, size_t size, size_t nmemb, void* userData);

public:
    GithubDownloader();

    void download(const std::string& githubUser, const std::string& repo, const std::string& path, const std::string& savePath);

    ~GithubDownloader();
};