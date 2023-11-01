cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pshell_exec C CXX ASM)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++ CACHE PATH "" FORCE)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/pshell)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/pshell_example)

add_executable(pshell_exec main.c)

pico_enable_stdio_usb(pshell_exec 1)
pico_enable_stdio_uart(pshell_exec 0)
pico_add_extra_outputs(pshell_exec)

target_link_libraries(pshell_exec pico_stdlib pshell pshell_example)
