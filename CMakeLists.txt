cmake_minimum_required(VERSION 2.8.11)

project(bdb)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

SET(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 11)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

qt5_wrap_ui(UI_HEADERS mainwindow.ui)

# Tell CMake to create the helloworld executable
add_executable(bdb bdb.cpp mainwindow.cpp ${UI_HEADERS})

#target_link_libraries (bdb mainwindow)

# Use the Widgets module from Qt 5.
target_link_libraries(bdb Qt5::Widgets)
