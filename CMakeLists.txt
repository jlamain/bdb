cmake_minimum_required(VERSION 2.8.11)

project(bdb)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Xml REQUIRED)

add_executable(bdb MACOSX_BUNDLE bdb.cpp mainwindow.cpp mainwindow.ui discmodel.cpp disc.h discmodel.h nicam.h  genre.h)

target_link_libraries(bdb Qt5::Widgets Qt5::Xml)
