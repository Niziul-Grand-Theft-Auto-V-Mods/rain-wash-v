# Require a recent enough CMake version for the features we use
cmake_minimum_required(VERSION 3.27)

# Declare the project: name, language, version and optional description
project(rain-wash-v
    LANGUAGES CXX
    VERSION 0.1.3.0
    DESCRIPTION "A mod that incorporates the feature from GTA IV where rain cleans the vehicle's dirt."
)

# ---------------- C++ standard configuration ----------------
# Use C++17 for all targets unless overridden
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json (useful for IDEs, clangd, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---------------- Compiler warnings / flags -----------------
# Prefer target-specific options, but we gather them here for MSVC
if(MSVC)
    # /EHsc   : standard C++ exception handling
    # /W4     : warning level 4 (high)
    # /permissive- : enforce strict C++ conformance
    set(RAIN_WASH_V_WARNING_FLAGS /EHsc /W4 /permissive-)
endif()

# ---------------- Library target definition -----------------
# Build the main plugin as a shared library (.dll which we will rename to .asi)
add_library(rain-wash-v SHARED
    src/main.cpp
    src/script.cpp
    src/util/game.cpp
    src/util/keyboard.cpp
    src/util/post_ticker.cpp
    src/util/settings.cpp
    src/util/wash.cpp
)

# Apply warning flags only to this target (and only if defined, e.g. on MSVC)
target_compile_options(rain-wash-v PRIVATE ${RAIN_WASH_V_WARNING_FLAGS})

# ---------------- ScriptHookV configuration -----------------
# Path to ScriptHookV import library (.lib)
# Marked CACHE so users can override it from cmake-gui / ccmake
set(SCRIPTHOOKV_LIB
    "${CMAKE_SOURCE_DIR}/lib/shv/ScriptHookV.lib"
    CACHE FILEPATH "ScriptHookV import library"
)

# ---------------- Linking -----------------------
# Link against ScriptHookV
target_link_libraries(rain-wash-v PRIVATE
    "${SCRIPTHOOKV_LIB}"
)

# ---------------- Configuration‑specific defines ----------------
# Define _DEBUG for Debug builds, NDEBUG for Release/RelWithDebInfo
target_compile_definitions(rain-wash-v PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
    $<$<CONFIG:RelWithDebInfo>:NDEBUG>
)

# ---------------- Output naming / versioning ----------------
# On Windows, the shared library normally has .dll extension.
# We override it to .asi so ScriptHookV treats it as a plugin.
set_target_properties(rain-wash-v PROPERTIES
    OUTPUT_NAME "Rain-wash-v"
    SUFFIX ".asi"
    VERSION ${PROJECT_VERSION}
)
