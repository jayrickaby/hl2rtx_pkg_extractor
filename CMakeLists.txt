cmake_minimum_required(VERSION 4.1)
project(hl2rtx_pkg_extractor)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_subdirectory(src)

target_link_libraries(hl2rtx_pkg_extractor
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

