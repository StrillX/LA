cmake_minimum_required(VERSION 3.15)
project(ProjetoLA C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoLA main.c dados.c dados.h logica.c logica.h interface.c interface.h)