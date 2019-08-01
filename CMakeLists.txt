cmake_minimum_required(VERSION 3.5)
project(_all)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Initialize the needed conan files. Allows us to link to the libraries.
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup(TARGETS)

# Force high error level. This should simply be useful for preventing pulling in
# libraries with higher error levels later.
if (MSVC)
    add_compile_options(/W3 /WX)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-W -Wall -Werror)
endif()

add_library(kabosu STATIC
    inc/kabosu/kabosu.h
    src/windows.c
)
target_include_directories(kabosu PUBLIC inc)
target_link_libraries(kabosu ${CONAN_TARGETS})

add_executable(test test/main.c)
target_link_libraries(test PRIVATE kabosu)