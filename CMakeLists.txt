# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.10...3.28)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("VehicleDynamicsSimulation")

# External deps
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw ${CMAKE_BINARY_DIR}/glfw)

# GLAD
add_library(glad
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/external/glad/include
)

# Executable
add_executable(VehicleDynamicsSimulation
    VehicleDynamicsSimulation/main.cpp
    VehicleDynamicsSimulation/HelperFunctions/HelperFunctionsOpenGL.cpp
)

target_include_directories(VehicleDynamicsSimulation PRIVATE
    ${CMAKE_SOURCE_DIR}/VehicleDynamicsSimulation
)

target_link_libraries(VehicleDynamicsSimulation
    PRIVATE
    glfw
    glad
)

# Link platform-specific OpenGL libraries/frameworks
if (WIN32)
    target_link_libraries(VehicleDynamicsSimulation PRIVATE opengl32)
elseif(APPLE)
    # Use the OpenGL framework on macOS
    target_link_libraries(VehicleDynamicsSimulation PRIVATE "-framework OpenGL")
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(VehicleDynamicsSimulation PRIVATE OpenGL::GL)
endif()

set_property(TARGET VehicleDynamicsSimulation PROPERTY CXX_STANDARD 20)

# Put all runtime outputs (exe and DLLs) into a single, predictable folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# If an "assets/" folder exists in the source tree, copy it to the runtime output
if(EXISTS ${CMAKE_SOURCE_DIR}/assets)
    file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
