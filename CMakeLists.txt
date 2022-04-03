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

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#this project
project(SpvGenTwo VERSION 1.0 DESCRIPTION "SPIR-V codegen library")

cmake_option(SPVGENTWO_ENABLE_OPERANDVALIDATION "Enable instruction operand validation via ITypeInferenceAndVailation" TRUE)
cmake_option(SPVGENTWO_ENABLE_WARNINGS "Enable Warnings" TRUE)
cmake_option(SPVGENTWO_LOGGING "Enable Logging" TRUE)
cmake_option(SPVGENTWO_REPLACE_PLACEMENTNEW "Don't use replacement new from <new>" TRUE)
cmake_option(SPVGENTWO_REPLACE_TRAITS "Use custom traits instead of <type_traits>" TRUE)
cmake_option(SPVGENTWO_BUILD_EXAMPLES "Build examples" FALSE)
cmake_option(SPVGENTWO_BUILD_DISASSEMBLER "Build disassembler" FALSE)
cmake_option(SPVGENTWO_BUILD_REFLECT "Build reflect" FALSE)
cmake_option(SPVGENTWO_BUILD_LINKER "Build linker" FALSE)
cmake_option(SPVGENTWO_BUILD_TESTS "Build catch2 tests" FALSE)
cmake_option(SPVGENTWO_DEBUG_HEAP_ALLOC "Log heap allocations" FALSE)

function(cmake_add_warnings target_project)

if(${SPVGENTWO_ENABLE_WARNINGS})

	set(CXX_FLAGS_GNU_STYLE OFF)
	set(CXX_FLAGS_MSVC_STYLE OFF)
	
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		set(CXX_FLAGS_GNU_STYLE ON)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
		set(CXX_FLAGS_GNU_STYLE ON)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		if ("${CMAKE_CXX_SIMULATE_ID}" STREQUAL "MSVC")
			set(CXX_FLAGS_MSVC_STYLE ON)
		else ()
			set(CXX_FLAGS_GNU_STYLE ON)
		endif ()
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
		set(CXX_FLAGS_MSVC_STYLE ON)
	else ()
		message(STATUS "Assuming GNU CXX")
		set(CXX_FLAGS_GNU_STYLE ON)
	endif ()

	target_compile_options(${target_project} PRIVATE
		$<$<BOOL:${CXX_FLAGS_GNU_STYLE}>:-Werror -Wall -Wextra -pedantic-errors -Wno-unknown-pragmas>    
        $<$<BOOL:${CXX_FLAGS_MSVC_STYLE}>:/WX /W4 /permissive-> )
		
	message(STATUS "Warnings enabled for ${target_project}")
endif()

endfunction()

#lib sources
add_sources("misc/*.natvis" "lib_sources")
add_sources("lib/source/*.cpp" "lib_sources")
add_sources("lib/include/spvgentwo/*.h" "lib_sources")
add_sources("lib/include/spvgentwo/*.inl" "lib_sources")
add_include_folder("lib/include" "lib_includes")

#lib project
add_library(SpvGenTwoLib "${lib_sources}")
target_include_directories(SpvGenTwoLib PUBLIC "${lib_includes}")
cmake_add_warnings(SpvGenTwoLib)

#common sources - shared between tools, examples and tests
add_sources("common/source/*.cpp" "common_sources")
add_sources("common/include/common/*.h" "common_sources")
add_sources("common/include/common/*.inl" "common_sources")
add_include_folder("common/include" "common_includes")

add_library(SpvGenTwoCommon "${common_sources}")
target_include_directories(SpvGenTwoCommon PRIVATE "${lib_includes}")
target_include_directories(SpvGenTwoCommon PUBLIC "${common_includes}")
target_link_libraries(SpvGenTwoCommon PRIVATE SpvGenTwoLib)
cmake_add_warnings(SpvGenTwoCommon)

#disassembler project
if(${SPVGENTWO_BUILD_DISASSEMBLER})
	add_sources("dis/source/*.cpp" "dis_sources")
	add_sources("dis/include/dis/*.h" "dis_sources")
	add_include_folder("dis/include" "dis_includes")

	add_executable(SpvGenTwoDisassembler "${dis_sources}")
	target_include_directories(SpvGenTwoDisassembler PUBLIC "${dis_includes};${common_includes}")
	target_link_libraries(SpvGenTwoDisassembler PRIVATE SpvGenTwoLib SpvGenTwoCommon)
	cmake_add_warnings(SpvGenTwoDisassembler)
endif()

#reflection project
if(${SPVGENTWO_BUILD_REFLECT})
	add_sources("refl/source/*.cpp" "refl_sources")
	add_sources("refl/include/refl/*.h" "refl_sources")
	add_include_folder("refl/include" "refl_includes")

	add_executable(SpvGenTwoReflect "${refl_sources}")
	target_include_directories(SpvGenTwoReflect PUBLIC "${refl_includes};${common_includes}")
	target_link_libraries(SpvGenTwoReflect PRIVATE SpvGenTwoLib SpvGenTwoCommon)
	cmake_add_warnings(SpvGenTwoReflect)
endif()

#reflection project
if(${SPVGENTWO_BUILD_LINKER})
	add_sources("link/source/*.cpp" "linker_sources")
	add_sources("link/include/link/*.h" "linker_sources")
	add_include_folder("link/include" "linker_includes")

	add_executable(SpvGenTwoLinker "${linker_sources}")
	target_include_directories(SpvGenTwoLinker PUBLIC "${linker_includes};${common_includes}")
	target_link_libraries(SpvGenTwoLinker PRIVATE SpvGenTwoLib SpvGenTwoCommon)
	cmake_add_warnings(SpvGenTwoLinker)
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

#test project
if(${SPVGENTWO_BUILD_TESTS})
	Include(FetchContent)

	FetchContent_Declare(
	  Catch2
	  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	  GIT_TAG        v3.0.0-preview4
	)

	FetchContent_MakeAvailable(Catch2)

	list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

	add_sources("test/source/*.cpp" "test_sources")
	add_sources("test/include/test/*.h" "test_sources")
	add_include_folder("test/include" "test_includes")

	add_executable(SpvGenTwoTests "${test_sources}")
	target_include_directories(SpvGenTwoTests PUBLIC "${test_includes};${common_includes}")
	target_link_libraries(SpvGenTwoTests PRIVATE SpvGenTwoLib SpvGenTwoCommon Catch2::Catch2WithMain)
	
	include(CTest)
	include(Catch)
	enable_testing()
	catch_discover_tests(SpvGenTwoTests)
endif()

message(STATUS "")
