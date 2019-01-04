cmake_minimum_required(VERSION 3.10)
project(3ATS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(3ATS
        ADS_pirmas1.1.c
        BigInt.c
        BigInt.h
        funkcijos1.h
        main.c)
