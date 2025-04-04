cmake_minimum_required(VERSION 3.20)

project(tcp_packets)
set(CMAKE_C_STANDARD 17)

set(HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/game_server.h
    ${CMAKE_SOURCE_DIR}/src/player.h
    ${CMAKE_SOURCE_DIR}/src/myerror.h
    ${CMAKE_SOURCE_DIR}/src/card.h
)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.c)

add_executable(server ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(server PRIVATE ${CMAKE_SOURCE_DIR}/pch/pch.h)

if (WIN32)
    target_link_libraries(server wsock32 ws2_32)
endif()