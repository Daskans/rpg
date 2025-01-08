cmake_minimum_required(VERSION 3.20)
project(rpg VERSION 0.1.0 LANGUAGES C)

# C standard
set(CMAKE_C_STANDARD 23)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

add_subdirectory(lib/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL3_image EXCLUDE_FROM_ALL)

file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Headers
include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    SYSTEM PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL3/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL3_image/include
)


# Link SDL3
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
    SDL3_image::SDL3_image
)

# cmake -S . -B build
# cmake --build build
# ./build/rpg