cmake_minimum_required(VERSION 3.12)

add_library(downloader GithubDownloader.cpp)

target_link_directories(downloader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})




