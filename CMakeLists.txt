cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project($Jetson_rp2040)

pico_sdk_init()

set(SRC_LIST main.c)

if (RP2040_FACTORY)
	set(SRC_LIST ${SRC_LIST} bin.c)
endif()

add_executable(Jetson_rp2040 ${SRC_LIST})

target_link_libraries(Jetson_rp2040
    pico_stdlib
    hardware_flash
	)

if (RP2040_FACTORY)
    add_definitions(-DRP2040_FACTORY=1)
    add_definitions(-DRP2040_USER=0)
	pico_set_linker_script(Jetson_rp2040 ${PROJECT_SOURCE_DIR}/configs/rp2040_factory.ld)
else()
    add_definitions(-DRP2040_FACTORY=0)
    add_definitions(-DRP2040_USER=1)
    pico_set_linker_script(Jetson_rp2040 ${PROJECT_SOURCE_DIR}/configs/rp2040_user.ld)
	pico_set_binary_type(Jetson_rp2040 no_flash)
endif()

pico_add_extra_outputs(Jetson_rp2040)
