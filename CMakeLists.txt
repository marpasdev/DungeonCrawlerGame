cmake_minimum_required(VERSION 3.16)
project(dungeoncrawlergame)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(dungeoncrawlergame ${SOURCES})

target_include_directories(dungeoncrawlergame PRIVATE src)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
target_link_libraries(dungeoncrawlergame SFML::Graphics SFML::Window SFML::System)

add_custom_command(TARGET dungeoncrawlergame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/textures
    $<TARGET_FILE_DIR:dungeoncrawlergame>/textures
)
