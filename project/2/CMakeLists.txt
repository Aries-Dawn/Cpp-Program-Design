cmake_minimum_required(VERSION 3.10)

project(matmul)

aux_source_directory(. DIR_SRCS)

include_directories(include)

add_executable(matmul ${DIR_SRCS})