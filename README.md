
# Rag: A rank aggregation library

A rank aggregation library implementing several popular methods.

## Getting Started

### Prerequisites

This project requires a compiler with C++17 support and CMake 3.14+.

### Usage

...

## CMake options

The following CMake options are made available by this project:

- WERROR: Treat warnings as errors
- GIT_SUBMODULE: Check submodules during build
- BUILD_SHARED_LIBS: Build shared libraries
- BUILD_TESTING: Build the testing tree
  - Run with `cd tests/ && ctest`
- BUILD_SAMPLES: Build sample applications
  - Run with `./bin/mytemplate.example`
- ENABLE_COVERAGE: Enable code coverage reporting with Codecov
  - Run with `make mytemplate.coverage`
- ENABLE_CLANG_FORMAT: Run clang-format on all files in src/ and include/
  - Run with `make format`
- ENABLE_ASAN: Enable Google AddressSanitizer
  - Run with `cd tests/ && ctest`
- ENABLE_USAN: Enable Google UndefinedBehaviorSanitizer
  - Run with `cd tests/ && ctest`
- ENABLE_TSAN: Enable Google ThreadSanitizer
  - Run with `cd tests/ && ctest`
- ENABLE_VALGRIND: Enable Valgrind
  - Run with `ctest -T memcheck`

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](tags).

## Authors

- **Patrick Cox** - [paddy74](https://github.com/paddy74)
