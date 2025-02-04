# Code inspired by the following projects:
# - https://gitlab.com/CLIUtils/modern-cmake
# - https://github.com/TheLartians/ModernCppStarter

cmake_minimum_required(VERSION 3.19...3.28)

project(CmakeCpp
    VERSION 1.0
    DESCRIPTION "CMake C++ project"
    LANGUAGES CXX
)

option(${PROJECT_NAME}_BUILD_TOOLS "Builds the applications" OFF)

# Disable in-source builds
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Set output folders
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)
endif()

include (cmake/CPM.cmake)

# Declare here all your dependencies

# Use fmtlib and nlohmann::json as an example
CPMAddPackage("gh:fmtlib/fmt#10.2.1")
CPMAddPackage("gh:nlohmann/json@3.11.3")
CPMAddPackage(
  GITHUB_REPOSITORY "google/benchmark"
  VERSION 1.9.1
  OPTIONS "BENCHMARK_ENABLE_TESTING OFF"
)

# The compiled library code is here
add_subdirectory(lib)

if (${PROJECT_NAME}_BUILD_TOOLS)
  # The executable code is here
  add_subdirectory(app)
endif()

# Testing only available if this is the main app
# Emergency override ${PROJECT_NAME}_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR ${PROJECT_NAME}_BUILD_TESTING)
    AND BUILD_TESTING)
  CPMAddPackage(
    GITHUB_REPOSITORY google/googletest
    VERSION 1.14.0
    OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
    EXCLUDE_FROM_ALL
    SYSTEM
  )
  add_subdirectory(test)
endif()

