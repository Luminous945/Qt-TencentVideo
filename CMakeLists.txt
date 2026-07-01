cmake_minimum_required(VERSION 3.16)

project(Tencne)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

file(GLOB_RECURSE HEADERS
    src/*.h
)

file(GLOB_RECURSE UIS
    src/*.ui
)

file(GLOB_RECURSE RES
    resources/*.qrc
)

add_executable(Tencne
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${RES}
)

target_link_libraries(Tencne Qt6::Widgets)