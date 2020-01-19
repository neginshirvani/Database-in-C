cmake_minimum_required(VERSION 3.13)
project(DataBase C)

set(CMAKE_C_STANDARD 99)

add_executable(DataBase main.c db.c cmake-build-debug/structres.c)