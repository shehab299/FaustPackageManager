#include "GithubDownloader.h"
#include "../Exceptions/DownloadException.h"
#include <filesystem>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

GithubDownloader::GithubDownloader(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    handle = curl_easy_init();
}

size_t GithubDownloader::write_data(void* ptr, size_t size, size_t nmemb, void* userData) {

    std::ofstream* file = static_cast<std::ofstream*>(userData);

    if (!file->is_open()) {
        throw DownloadException("File not open");
    }

    file->write(static_cast<char*>(ptr), size * nmemb);

    return size * nmemb;
}

void GithubDownloader::download(const std::string& githubUser, const std::string& repo, const std::string& path, const std::string& savePath)
{
    std::string url = "https://raw.githubusercontent.com/" + githubUser + "/" + repo + "/" + path;

    std::ofstream file(savePath, std::ios::binary);
    if (!file.is_open()) {
        throw DownloadException("Can't open file: " + savePath);
    }

    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &GithubDownloader::write_data);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &file);

    CURLcode res = curl_easy_perform(handle);
    file.close();

    if (res != CURLE_OK) {
        std::filesystem::remove(savePath); 
        throw DownloadException("Download failed: " + std::string(curl_easy_strerror(res)));
    }

    long http_code = 0;
    curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code == 404) {
        std::filesystem::remove(savePath);  // Remove the incomplete file
        throw DownloadException("File not found (HTTP 404)");
    }
}


GithubDownloader::~GithubDownloader(){
    curl_easy_cleanup(handle);
    curl_global_cleanup();   
}
