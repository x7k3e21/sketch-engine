
cmake_minimum_required(VERSION 4.2)

set(SK_ENGINE_TARGET_NAME "sketch-engine" CACHE INTERNAL "")

set(SK_ENGINE_VERSION_MAJOR 1 CACHE INTERNAL "")
set(SK_ENGINE_VERSION_MINOR 0 CACHE INTERNAL "")

option(USE_WAYLAND "Use Wayland instead of X11 on Linux" ON)

file(GLOB_RECURSE SK_ENGINE_HEADER_FILES
    "include/*.h"
    "include/*.hpp"
)

file(GLOB_RECURSE SK_ENGINE_SOURCE_FILES
    "source/*.c"
    "source/*.cpp"
)

file(GLOB_RECURSE SK_ENGINE_EXCLUDE_HEADER_FILES
    "include/platform/wayland/*.h"
    "include/platform/wayland/*.hpp"

    "include/platform/windows/*.h"
    "include/platform/windows/*.hpp"

    "include/platform/x11/*.h"
    "include/platform/x11/*.hpp"
)

list(REMOVE_ITEM SK_ENGINE_HEADER_FILES ${SK_ENGINE_EXCLUDE_HEADER_FILES})

file(GLOB_RECURSE SK_ENGINE_EXCLUDE_SOURCE_FILES
    "source/platform/wayland/*.c"
    "source/platform/wayland/*.cpp"

    "source/platform/windows/*.c"
    "source/platform/windows/*.cpp"

    "source/platform/x11/*.c"
    "source/platform/x11/*.cpp"
)

list(REMOVE_ITEM SK_ENGINE_SOURCE_FILES ${SK_ENGINE_EXCLUDE_SOURCE_FILES})

add_library(${SK_ENGINE_TARGET_NAME} SHARED
    ${SK_ENGINE_HEADER_FILES}
    ${SK_ENGINE_SOURCE_FILES}
)

add_library(sketch::engine ALIAS ${SK_ENGINE_TARGET_NAME})

set_property(TARGET ${SK_ENGINE_TARGET_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${SK_ENGINE_TARGET_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${SK_ENGINE_TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Building '${SK_ENGINE_TARGET_NAME}' for Windows (WinAPI)")

    file(GLOB_RECURSE SK_ENGINE_PLATFORM_HEADER_FILES
        "include/platform/windows/*.h"
        "include/platform/windows/*.hpp"
    )

    file(GLOB_RECURSE SK_ENGINE_PLATFORM_SOURCE_FILES
        "source/platform/windows/*.c"
        "source/platform/windows/*.cpp"
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    if(USE_WAYLAND)
        message(STATUS "Building '${SK_ENGINE_TARGET_NAME}' for Linux (Wayland)")

        find_package(Wayland)

        if(WAYLAND_FOUND)
            file(GLOB_RECURSE SK_ENGINE_PLATFORM_HEADER_FILES
                "include/platform/wayland/*.h"
                "include/platform/wayland/*.hpp"
            )

            file(GLOB_RECURSE SK_ENGINE_PLATFORM_SOURCE_FILES
                "source/platform/wayland/*.c"
                "source/platform/wayland/*.cpp"
            )

            target_include_directories(${SK_ENGINE_TARGET_NAME} PUBLIC 
                ${WAYLAND_CLIENT_INCLUDE_DIRS}
            )

            target_link_libraries(${SK_ENGINE_TARGET_NAME} PUBLIC
                ${WAYLAND_CLIENT_LIBRARIES}
            )

            target_compile_options(${SK_ENGINE_TARGET_NAME} PUBLIC
                ${WAYLAND_CLIENT_CFLAGS}
                ${WAYLAND_CLIENT_CFLAGS_OTHER}
            )
            
            target_link_options(${SK_ENGINE_TARGET_NAME} PUBLIC
                ${WAYLAND_CLIENT_LDFLAGS}
                ${WAYLAND_CLIENT_LDFLAGS_OTHER}
            )
        else()
            message(WARNING "Failed to locate Wayland installation, defaulting to X11!")
        endif()
    endif()

    if(NOT USE_WAYLAND OR NOT WAYLAND_FOUND)
        message(STATUS "Building '${SK_ENGINE_TARGET_NAME}' for Linux (X11)")

        find_package(X11)

        if(X11_FOUND)
            file(GLOB_RECURSE SK_ENGINE_PLATFORM_HEADER_FILES
                "include/platform/x11/*.h"
                "include/platform/x11/*.hpp"
            )

            file(GLOB_RECURSE SK_ENGINE_PLATFORM_SOURCE_FILES
                "source/platform/x11/*.c"
                "source/platform/x11/*.cpp"
            )

            target_include_directories(${SK_ENGINE_TARGET_NAME} PUBLIC 
                ${X11_INCLUDE_DIR}
            )

            target_link_libraries(${SK_ENGINE_TARGET_NAME} PUBLIC
                ${X11_LIBRARIES}
            )
        else()
            message(FATAL_ERROR "Failed to locate X11 installation!")
        endif()
    endif()
endif()

target_sources(${SK_ENGINE_TARGET_NAME} PUBLIC
    ${SK_ENGINE_PLATFORM_HEADER_FILES}
    ${SK_ENGINE_PLATFORM_SOURCE_FILES}
)