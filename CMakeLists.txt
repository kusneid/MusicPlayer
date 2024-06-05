cmake_minimum_required(VERSION 3.16)
project(MusicPlayer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# sfml download
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


file(GLOB_RECURSE SOURCES 
     "src/decoding/*.cpp"
     "src/org/*.cpp"
     "src/ui/*.cpp"
     "src/*.cpp")

file(GLOB_RECURSE HEADERS 
     "include/decoding/*.h"
     "include/org/*.h"
     "include/ui/*.h"
     "include/*.h")

include_directories(include)

add_executable(MusicPlayer ${SOURCES} ${HEADERS})

# Linking SFML libraries
target_link_libraries(MusicPlayer PRIVATE sfml-graphics sfml-audio)


target_compile_features(MusicPlayer PRIVATE cxx_std_17)

# Copy icons to build directory
file(GLOB ICONS "resources/icons/*.png")
file(COPY ${ICONS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/icons)

# Copy fonts to build directory
file(GLOB FONTS "resources/fonts/*.ttf")
file(COPY ${FONTS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/fonts)



install(TARGETS MusicPlayer)

# Install icons
install(FILES ${ICONS} DESTINATION build/icons)
install(FILES ${FONTS} DESTINATION build/fonts)
