
# C++ Cross-Platform CI/CD

A training project for learning cross-platform CI/CD
using Jenkins, Docker, CMake and modern C++.

## Technologies

- C++20
- CMake
- Ninja
- GoogleTest
- GCC
- Clang
- MSVC
- cppcheck
- clang-tidy
- clang-format
- Jenkins

## Project structure

- `include/` - public headers
- `src/` - application and library source code
- `tests/` - unit tests
- `cmake/` - CMake helper modules
- `scripts/` - automation scripts

## Build requirements

- CMake 3.25+
- Ninja
- GCC or Clang
- C++20 support
- Internet connection for initial GoogleTest download

## Build with GCC

```bash
cmake --preset linux-gcc-debug
cmake --build --preset gcc-debug
ctest --preset gcc-debug
```

## Build with Clang

```bash
cmake --preset linux-clang-debug
cmake --build --preset clang-debug
ctest --preset clang-debug
```

## Build Release

```bash
cmake --preset linux-gcc-release
cmake --build --preset gcc-release
ctest --preset gcc-release
```

## Run application

```bash
./build/gcc-debug/tinycalc
```

## CI/CD roadmap

1. Local C++ build and tests
2. Jenkins Controller
3. Linux Jenkins agents
4. Parallel Multibranch Pipeline
5. Separate Build job
6. Package job
7. Windows agent
8. Release pipeline
