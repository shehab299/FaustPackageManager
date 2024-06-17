cmake_minimum_required(VERSION 3.12)

project(pkgManager VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CURL REQUIRED)

add_subdirectory(Downloader)
add_subdirectory(PkgUrl)
add_subdirectory(Exceptions)


add_executable(main main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Registry/Registry.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Registry)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(main PUBLIC downloader pkgurl ${CURL_LIBRARIES})

