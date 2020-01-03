cmake_minimum_required(VERSION 3.12.0 FATAL_ERROR)

macro(add_sources expression sources)
	file(GLOB source_files RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "${expression}")
	set(${sources} "${${sources}};${source_files}")
endmacro()

macro(add_include_folder include_folder includes)
	set(${includes} "${${includes}};${CMAKE_CURRENT_LIST_DIR}/${include_folder}")
endmacro()

function(cmake_option option description default)
	option(${option} description ${default})
	if(${option})
		message(STATUS "'${option}' is TRUE")
		add_definitions(-D"${option}"=1)
	else()
		message(STATUS "'${option}' is FALSE")
	endif()
endfunction()

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
find_package(Vulkan)

set(SPIRV_INCLUDE_DIR "${Vulkan_INCLUDE_DIR}/vulkan/" CACHE STRING "Path containing spirv.hpp11 and GLSL.std.450.h")

cmake_option(SPVGENTWO_NO_LOGGING "Disable Logging" FALSE)
cmake_option(SPVGENTWO_DONT_REPLACE_PLACEMENTNEW "Use replacement new from <new> if TRUE" FALSE)
cmake_option(SPVGENTWO_DONT_REPLACE_TRAITS "Use traits from <type_traits> if TRUE" FALSE)

#lib sources
add_sources("lib/source/*.cpp" "lib_sources")
add_include_folder("lib/include" "lib_includes")

set(lib_includes "${lib_includes}")

#lib project
add_library(lib SHARED "${lib_sources}")
target_include_directories(lib PUBLIC "${lib_includes}")
target_include_directories(lib PUBLIC "${SPIRV_INCLUDE_DIR}")

#common sources - shared between examples and tests
add_sources("common/source/*.cpp" "common_sources")
add_include_folder("common/include" "common_includes")

#cli project
add_sources("example/source/*.cpp" "example_sources")
add_include_folder("example/include" "example_includes")

add_executable(example "${example_sources};${common_sources}")
target_include_directories(example PUBLIC "${example_includes};${common_includes}")
target_link_libraries(example PUBLIC lib)

message(STATUS "")