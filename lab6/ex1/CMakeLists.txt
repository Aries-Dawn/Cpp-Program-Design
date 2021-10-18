cmake_minimum_required(VERSION 3.10)

project(main,out)

aux_source_directory(. DIR_SRCS)

include_directories(include)

add_executable(main.out ${DIR_SRCS})