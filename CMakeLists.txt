cmake_minimum_required(VERSION 3.15)

project(SimpleFileManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui UiTools)

# Add your source files
set(SOURCES
    src/main.cpp
    src/components/MainWindow.cpp
    src/components/DirectoryViewWidget.cpp
    src/components/DirectoryPathWidget.cpp
    src/components/DirectoryPathInput.cpp
    src/components/FileSystemItemWidget.cpp
    src/components/DirectoryItemWidget.cpp
    src/components/FileItemWidget.cpp
    src/components/QuickDirectoryAccessWidget.cpp
    src/components/QuickDirAccessEntryWidget.cpp
    src/layouts/FlowLayout.cpp
    src/data_structures/DirectoryItem.cpp
    src/services/DirectoryNavigationService.cpp
)

set(HEADERS
    src/components/MainWindow.h
    src/components/DirectoryViewWidget.h
    src/components/DirectoryPathWidget.h
    src/components/DirectoryPathInput.h
    src/components/FileSystemItemWidget.h
    src/components/DirectoryItemWidget.h
    src/components/FileItemWidget.h
    src/components/QuickDirectoryAccessWidget.h
    src/components/QuickDirAccessEntryWidget.h
    src/layouts/FlowLayout.h
    src/data_structures/DirectoryItem.h
    src/services/DirectoryNavigationService.h
    src/services/ThumbnailProviderService.h
    src/services/LinuxThumbnailProviderService.h
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
    src/data_structures
    src/os
    src/services
)

# === Doxygen Integration ===
find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    message(${DOXYGEN_IN})
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    message(${DOXYGEN_OUT})

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else()
    message(STATUS "Doxygen not found. 'doc_doxygen' target will be unavailable.")
endif()

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
