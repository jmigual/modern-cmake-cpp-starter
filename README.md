# Minimal Modern CMake C++ starter

This is a minimal project starter for modern CMake and C++20. You can just clone/fork this repository and start writing your code.

## Table of contents

- [Minimal Modern CMake C++ starter](#minimal-modern-cmake-c-starter)
  - [Table of contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Compilation](#compilation)
    - [CMake presets (recommended)](#cmake-presets-recommended)
  - [Acknowledgements](#acknowledgements)
  - [TODO](#todo)

## Introduction

This project defines a simple C++ library and a main executable that uses the library. The project is organized as follows:

- `lib/`: Contains the source code of the library.
- `app/`: Contains the source code of the main executable.
- `test/`: Contains the source code of the tests.

Additionally, dependencies can be imported using the [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) library. For example, to import the [GoogleTest](https://github.com/google/googletest) library, you can add the following lines to the `CMakeLists.txt` file:

```cmake
include(cmake/CPM.cmake)
CPMAddPackage(
  GITHUB_REPOSITORY google/googletest
  VERSION 1.14.0
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
  EXCLUDE_FROM_ALL
  SYSTEM
)
```

## Compilation

To build the code you can use the following commands:

```bash
cmake -S . -B build
cmake --build build
```

### CMake presets (recommended)

You can also use the CMake presets to build the code:

```bash
cmake -S . -B build --preset=default
cmake --build build --preset=Release
```

## Acknowledgements

This project is inspired by the following projects:

- [Modern CMake Starter](https://github.com/TheLartians/ModernCppStarter)
- [Modern CMake book](https://gitlab.com/CLIUtils/modern-cmake)

## TODO

- [ ] Add CMake install configuration
- [ ] Generate doxygen documentation

