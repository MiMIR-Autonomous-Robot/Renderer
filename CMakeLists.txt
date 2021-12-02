cmake_minimum_required (VERSION 3.1.0)

project(sdlTest)

file(GLOB MAIN_APP_SRC
	"./src/*.h"
	"./src/*.cpp"
	"./src/hal/*.cpp"
	"./scr/hal/*.h"
	"./src/arch/linux/*.cpp"
	"./src/arch/linux/*.h"
	"./include/*.h"
	"*.cpp"
)

add_executable(main_app ${MAIN_APP_SRC})

target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/hal)
target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/arch/linux)
target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

set(THREADS_PREFER_PTHREAD_FLAG ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(main_app
    -lSDL2
)