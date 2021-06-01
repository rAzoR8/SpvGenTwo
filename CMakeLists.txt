cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

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

if (MSVC)
	#enforce strictness on msvc
    add_compile_options(/W4 /permissive-)
endif()

#this project
project(SpvGenTwo VERSION 1.0 DESCRIPTION "SPIR-V codegen library")

cmake_option(SPVGENTWO_LOGGING "Enable Logging" TRUE)
cmake_option(SPVGENTWO_REPLACE_PLACEMENTNEW "Don't use replacement new from <new>" TRUE)
cmake_option(SPVGENTWO_REPLACE_TRAITS "Use custom traits instead of <type_traits>" TRUE)
cmake_option(SPVGENTWO_BUILD_EXAMPLES "Build examples" FALSE)
cmake_option(SPVGENTWO_BUILD_DISASSEMBLER "Build disassembler" FALSE)
cmake_option(SPVGENTWO_BUILD_REFLECT "Build reflect" FALSE)
cmake_option(SPVGENTWO_BUILD_LINKER "Build linker" FALSE)
cmake_option(SPVGENTWO_DEBUG_HEAP_ALLOC "Log heap allocations" FALSE)

#lib sources
add_sources("misc/*.natvis" "lib_sources")
add_sources("lib/source/*.cpp" "lib_sources")
add_sources("lib/include/spvgentwo/*.h" "lib_sources")
add_sources("lib/include/spvgentwo/*.inl" "lib_sources")
add_include_folder("lib/include" "lib_includes")

#lib project
add_library(SpvGenTwoLib "${lib_sources}")
target_include_directories(SpvGenTwoLib PUBLIC "${lib_includes}")

#common sources - shared between tools, examples and tests
add_sources("common/source/*.cpp" "common_sources")
add_sources("common/include/common/*.h" "common_sources")
add_sources("common/include/common/*.inl" "common_sources")
add_include_folder("common/include" "common_includes")

add_library(SpvGenTwoCommon "${common_sources}")
target_include_directories(SpvGenTwoCommon PRIVATE "${lib_includes}")
target_include_directories(SpvGenTwoCommon PUBLIC "${common_includes}")
target_link_libraries(SpvGenTwoCommon PRIVATE SpvGenTwoLib)

#disassembler project
if(${SPVGENTWO_BUILD_DISASSEMBLER})
	add_sources("dis/source/*.cpp" "dis_sources")
	add_sources("dis/include/dis/*.h" "dis_sources")
	add_include_folder("dis/include" "dis_includes")

	add_executable(SpvGenTwoDisassembler "${dis_sources}")
	target_include_directories(SpvGenTwoDisassembler PUBLIC "${dis_includes};${common_includes}")
	target_link_libraries(SpvGenTwoDisassembler PRIVATE SpvGenTwoLib SpvGenTwoCommon)
endif()

#reflection project
if(${SPVGENTWO_BUILD_REFLECT})
	add_sources("refl/source/*.cpp" "refl_sources")
	add_sources("refl/include/refl/*.h" "refl_sources")
	add_include_folder("refl/include" "refl_includes")

	add_executable(SpvGenTwoReflect "${refl_sources}")
	target_include_directories(SpvGenTwoReflect PUBLIC "${refl_includes};${common_includes}")
	target_link_libraries(SpvGenTwoReflect PRIVATE SpvGenTwoLib SpvGenTwoCommon)
endif()

#reflection project
if(${SPVGENTWO_BUILD_LINKER})
	add_sources("link/source/*.cpp" "linker_sources")
	add_sources("link/include/link/*.h" "linker_sources")
	add_include_folder("link/include" "linker_includes")

	add_executable(SpvGenTwoLinker "${linker_sources}")
	target_include_directories(SpvGenTwoLinker PUBLIC "${linker_includes};${common_includes}")
	target_link_libraries(SpvGenTwoLinker PRIVATE SpvGenTwoLib SpvGenTwoCommon)
endif()

#example project
if(${SPVGENTWO_BUILD_EXAMPLES})
	add_sources("example/source/*.cpp" "example_sources")
	add_sources("example/include/example/*.h" "example_sources")
	add_include_folder("example/include" "example_includes")

	add_executable(SpvGenTwoExample "${example_sources}")
	target_include_directories(SpvGenTwoExample PUBLIC "${example_includes};${common_includes}")
	target_link_libraries(SpvGenTwoExample PRIVATE SpvGenTwoLib SpvGenTwoCommon)
endif()

message(STATUS "")
