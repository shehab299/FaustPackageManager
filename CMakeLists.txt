cmake_minimum_required(VERSION 3.12)

project(pkgManager VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CURL REQUIRED)



file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(main ${SRC_FILES})

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main PUBLIC ${CURL_LIBRARIES})
