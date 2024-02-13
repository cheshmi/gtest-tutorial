# gtest-tutorial

# Introduction
This is a simple project to demonstrate how to use Google Test (gtest) for C++ unit testing.


## Installation

### Prerequisites
* C++ compiler
* CMake
* Git
* Google Test (already included in this repository)
* Python3 (for running the scripts and generating random data)

### Clone the repository
```bash
git clone https://github.com/cheshmi/gtest-tutorial.git
```

### Build the project
```bash
cd gtest-tutorial
cmake -S . -B build
cmake --build build
```

### Run the tests
There are two test suites in this project: `convolution_test` and `sampling_test`.
Tests for convolution:
```bash
./build/test/convolution_test
```

Tests for sampling:
```bash
./build/test/sampling_test
```

Tests for fft:
```bash
./build/test/fft_test
```

