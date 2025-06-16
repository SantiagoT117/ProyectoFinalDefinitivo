cmake_minimum_required(VERSION 3.16)
project(pruebas)

# 1. Recolecta todos los .cpp (incluyendo main.cpp)
file(GLOB SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

# 2. Declara el ejecutable
add_executable(pruebas ${SRC_FILES})

# 3. Indícale dónde están los headers
target_include_directories(pruebas
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)