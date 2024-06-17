cmake_minimum_required(VERSION 3.12)

add_library(pkgurl PkgUrl.cpp)

target_link_directories(pkgurl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})