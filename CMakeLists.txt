cmake_minimum_required(VERSION 3.8)
project(MultithreadingMonteCarlo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Multi.h Multi.cpp Single.h Single.cpp Const.h pcg_extras.hpp pcg_random.hpp pcg_uint128.hpp)
add_executable(MultithreadingMonteCarlo ${SOURCE_FILES})