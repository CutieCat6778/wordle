cmake_minimum_required(VERSION 3.10)

project(Wordle)

find_package(CURL CONFIG REQUIRED)
find_package(cJSON CONFIG REQUIRED)

add_executable(Wordle main.c)

target_link_libraries(Wordle PRIVATE CURL::libcurl)
target_link_libraries(Wordle PRIVATE cjson)
