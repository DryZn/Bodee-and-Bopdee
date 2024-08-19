cmake_minimum_required(VERSION 3.17)

project(BODEE_AND_BOPDEE VERSION 1.0 LANGUAGES CXX)

file(GLOB SOURCES "src/*.cpp")

include(FetchContent)

FetchContent_Declare(sdl
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.6/SDL2-2.30.6.zip
)
FetchContent_MakeAvailable(sdl)

FetchContent_Declare(sdl_image
    URL https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.2/SDL2_image-2.8.2.zip
)
FetchContent_MakeAvailable(sdl_image)

add_executable(Bodee_and_Bopdee ${SOURCES})

target_include_directories(Bodee_and_Bopdee PUBLIC inc)

target_link_libraries(Bodee_and_Bopdee SDL2_image SDL2)

if(WIN32)
    message("Adding dll")
    add_custom_command(
        TARGET Bodee_and_Bopdee POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:Bodee_and_Bopdee>"
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2_image::SDL2_image>" "$<TARGET_FILE_DIR:Bodee_and_Bopdee>"
        VERBATIM
    )
endif()

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
