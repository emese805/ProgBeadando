cmake_minimum_required(VERSION 3.9)
project(ProgBeadando)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProgBeadando main.cpp tests.h Bag/Bag.cpp Bag/Bag.h)