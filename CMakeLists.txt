set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
cmake_minimum_required(VERSION 3.5)

project(QtPlot LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.


find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall")

ADD_LIBRARY(libQCustomPlot
    qcustomplot.cpp
)
target_link_libraries(libQCustomPlot PRIVATE Qt5::Widgets Qt5::PrintSupport )

  add_executable(QtPlot
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )

configure_file(${Qt5Core_DIR}/../../../bin/libstdc++-6.dll ${PROJECT_SOURCE_DIR}/build/libstdc++-6.dll COPYONLY)
configure_file(${Qt5Core_DIR}/../../../bin/libwinpthread-1.dll ${PROJECT_SOURCE_DIR}/build/libwinpthread-1.dll COPYONLY)
configure_file(${Qt5Core_DIR}/../../../bin/Qt5Core.dll ${PROJECT_SOURCE_DIR}/build/Qt5Core.dll COPYONLY)
configure_file(${Qt5Core_DIR}/../../../bin/Qt5Gui.dll ${PROJECT_SOURCE_DIR}/build/Qt5Gui.dll COPYONLY)
configure_file(${Qt5Core_DIR}/../../../bin/Qt5PrintSupport.dll ${PROJECT_SOURCE_DIR}/build/Qt5PrintSupport.dll COPYONLY)
configure_file(${Qt5Core_DIR}/../../../bin/Qt5Widgets.dll ${PROJECT_SOURCE_DIR}/build/Qt5Widgets.dll COPYONLY)


target_link_libraries(QtPlot PRIVATE Qt5::Widgets libQCustomPlot )
