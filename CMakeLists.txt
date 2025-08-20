cmake_minimum_required(VERSION 3.20)
project(EstruturaDeDados)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Arvores Arvores/main.cpp)
#add_executable(listas Listas/main.cpp)
#add_executable(pilhas Pilhas/main.cpp)
