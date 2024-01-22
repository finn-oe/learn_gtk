cmake_minimum_required(VERSION 3.26)
project(learn_gtk C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_definitions(${GTK4_CFLAGS_OTHER})
set(SOURCE_FILES main.c)
add_executable(learn_gtk ${SOURCE_FILES})

target_link_libraries(learn_gtk ${GTK4_LIBRARIES})
