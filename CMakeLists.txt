cmake_minimum_required(VERSION 3.16)
project(Multiproject)

#salida out-of-source
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#incluir ambos subproyectos
add_subdirectory(Pruebas)