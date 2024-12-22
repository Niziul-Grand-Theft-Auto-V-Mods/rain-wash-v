cmake_minimum_required(VERSION 3.27)

project(Rainwashv
    LANGUAGES CXX
    VERSION 0.1.2.0
    DESCRIPTION "A mod that incorporates the feature from GTA IV where rain cleans the vehicle's dirt."
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

if(MSVC)
    add_compile_options(/EHsc /W4 /permissive- /std:c++17)
else()
    add_compile_options(-Wall -Wextra -pedantic -std=c++17)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PLATFORM x64)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PLATFORM}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PLATFORM}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PLATFORM}/bin)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

FetchContent_Declare(
    scripthookv
    URL https://ntscorp.ru/dev-c/ScriptHookV_SDK_1.0.617.1a.zip
)
FetchContent_MakeAvailable(scripthookv)

set(SCRIPTHOOKV_INC_DIR ${scripthookv_SOURCE_DIR}/inc)
set(SCRIPTHOOKV_LIB_DIR ${scripthookv_SOURCE_DIR}/lib)

add_library(ScriptHookV STATIC IMPORTED)
set_target_properties(ScriptHookV PROPERTIES
    IMPORTED_LOCATION ${SCRIPTHOOKV_LIB_DIR}/ScriptHookV.lib
    INTERFACE_INCLUDE_DIRECTORIES ${SCRIPTHOOKV_INC_DIR}
)

if(NOT TARGET ScriptHookV)
    message(FATAL_ERROR "ScriptHookV library was not properly fetched.")
endif()

add_library(Rainwashv SHARED
    inc/dllscript.h
    inc/util/natives.h
    inc/features/wash/wash.h
    inc/rage-engine/game/game.h
    inc/rage-engine/ui/feed-post/enums/feed_message_type.h
    inc/rage-engine/ui/feed-post/enums/feed_post_message_icon_type.h
    inc/rage-engine/ui/feed-post/feed_post.h
    src/dllscript.cpp
    src/features/wash/wash.cpp
    src/rage-engine/game/game.cpp
    src/rage-engine/ui/feed-post/feed_post.cpp
)
target_include_directories(Rainwashv PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/inc
)

target_link_libraries(Rainwashv
    PRIVATE ScriptHookV
)

target_compile_definitions(Rainwashv PRIVATE $<$<CONFIG:Debug>:_DEBUG> $<$<CONFIG:Release>:NDEBUG>)

set(GTA_V_DIR "D:/SteamLibrary/steamapps/common/Grand Theft Auto V" CACHE PATH "Path to GTA V installation directory")
if(NOT EXISTS "${GTA_V_DIR}")
    message(FATAL_ERROR "GTA_V_DIR is invalid or does not exist: ${GTA_V_DIR}")
endif()

add_custom_command(TARGET Rainwashv POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Rainwashv> "${GTA_V_DIR}/"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_CONFIGURATION_TYPES STREQUAL "Debug")
    add_custom_command(TARGET Rainwashv POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:Rainwashv> "${GTA_V_DIR}/"
    )
endif()

set_target_properties(Rainwashv PROPERTIES
    OUTPUT_NAME "Rain-wash-v"
    SUFFIX ".asi"
    DEBUG_POSTFIX ""
    RELWITHDEBINFO_POSTFIX ""
)
