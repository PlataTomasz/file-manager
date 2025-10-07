cmake_minimum_required(VERSION 3.15)

project(SimpleFileManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui UiTools)

# Add your source files
set(SOURCES
    src/main.cpp
    src/components/MainWindow.cpp
)

set(HEADERS
    src/components/MainWindow.h
)

set(UI

)

set(ICONS

)

set(IMAGES

)

# Enable automatic handling of MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(
    CMAKE_AUTOUIC_SEARCH_PATHS
    resources/ui
)
set(CMAKE_AUTORCC ON)

include_directories(
    src
    src/components
    src/data_containers
)

# Create the executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI}
    ${IMAGES}
)

# Link against Qt6
target_link_libraries(${PROJECT_NAME}
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::UiTools
)
