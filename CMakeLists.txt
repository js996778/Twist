cmake_minimum_required(VERSION 3.7)
project(Twist VERSION 3.0 LANGUAGES C CXX)

set(TWIST_VERSION ${PROJECT_VERSION})
set(TWIST_NAME "${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if (WIN32 OR MINGW)
	add_definitions(-DWINDOWS)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_definitions(-DJACK_HAS_PORT_RENAME)
add_definitions(-DTWIST_NAME="${TWIST_NAME}")
add_definitions(-DTWIST_VERSION="${TWIST_VERSION}")

find_package(SDL2 CONFIG REQUIRED)

add_subdirectory("${CMAKE_SOURCE_DIR}/src/editor/imgui")
add_subdirectory("${CMAKE_SOURCE_DIR}/deps/osdialog")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/taudio")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/twen")

include_directories(
	"deps/osdialog"
	"src/"
)

file(GLOB SRC
	"src/editor/*.h"
	"src/editor/*.cpp"
	"src/editor/*.hpp"
	"src/editor/imgui/*.h"
	"src/editor/imgui/*.cpp"
	"src/editor/imgui/*.hpp"
	"src/editor/nodes/*.hpp"
	"src/glad/*.h"
	"src/glad/*.cpp"
	"src/stb/*.h"
	"src/stb/*.cpp"
	"src/main.cpp"
)

if(WIN32 OR MINGW OR MSVC)
	set(SRC ${SRC} "resources.rc")
endif()

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
	SDL2
	osdialog
	ImGUI
	taudio
	twen
	stdc++fs
)

if (CMAKE_DL_LIBS)
	target_link_libraries(${PROJECT_NAME}
		${CMAKE_DL_LIBS}
	)
endif()
