cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

macro(add_sources expression sources)
	file(GLOB source_files RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "${expression}")
	set(${sources} "${${sources}};${source_files}")
endmacro()

macro(add_include_folder include_folder includes)
	set(${includes} "${${includes}};${CMAKE_CURRENT_LIST_DIR}/${include_folder}")
endmacro()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#this project
project(spvGenTwo)

#dependencies
find_package(Vulkan REQUIRED)

#lib sources
add_sources("lib/source/*.cpp" "lib_sources")
add_include_folder("lib/include" "lib_includes")

#set(STB_INCLUDE_PATH "${CMAKE_CURRENT_LIST_DIR}/thirdparty/stb/" CACHE STRING "")
#set(lib_includes "${lib_includes};${STB_INCLUDE_PATH}")
set(lib_includes "${lib_includes}")

#cli sources
add_sources("cli/source/*.cpp" "cli_sources")
add_include_folder("cli/include" "cli_includes")

#lib project
add_library(lib SHARED "${lib_sources}")
target_include_directories(lib PUBLIC "${lib_includes}")

target_include_directories(lib PRIVATE "${Vulkan_INCLUDE_DIR}")
#target_link_libraries(lib PRIVATE "${Vulkan_LIBRARIES}")

#find_package(Glslang REQUIRED)
#target_link_libraries(lib PRIVATE glslang SPIRV)

#cli project
add_executable(cli "${cli_sources}")
target_include_directories(cli PUBLIC "${cli_includes};${lib_includes};${Vulkan_INCLUDE_DIR}")
target_link_libraries(cli PUBLIC lib)

message(STATUS "")