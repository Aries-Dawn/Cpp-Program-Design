cmake_minimum_required(VERSION 3.10)

project(ex.out)

aux_source_directory(. DIR_SRCS)

include_directories(include)

add_executable(ex.out ${DIR_SRCS})