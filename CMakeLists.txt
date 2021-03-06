cmake_minimum_required(VERSION 3.5)

project(Calculator LANGUAGES CXX)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/QtTestCalculator")

include_directories(${SOURCE_DIR})

file(GLOB SOURCE_FILES
        "${SOURCE_DIR}/*.cpp"
        "${SOURCE_DIR}/*.qrc"
        "${SOURCE_DIR}/*.h"
        "${SOURCE_DIR}/*.ui"
	"${SOURCE_DIR}/*.md"
)

add_subdirectory(${TESTS_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

