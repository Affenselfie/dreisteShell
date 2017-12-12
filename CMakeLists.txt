cmake_minimum_required(VERSION 3.5)
project(dreisteShell C)

set(CMAKE_C_STANDARD 99)

add_executable(dreisteShell main.c)
install(PROGRAMS dreisteShell DESTINATION /bin)
