
# Download and unpack googletest at configure time
cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

# Create the test executable, mul_test, and link it with the
# GoogleTest and GoogleMock libraries.
add_executable(
        convolution_test
        test_utils.cpp
        convolution_test.cpp
)
target_link_libraries(
        convolution_test
        GTest::gtest_main
        swift_dsp
)

# Register test for sampling
add_executable(
        sampling_test
        test_utils.cpp
        sampling_test.cpp
)
target_link_libraries(
        sampling_test
        GTest::gtest_main
        swift_dsp
)


include(GoogleTest)
gtest_discover_tests(convolution_test)
gtest_discover_tests(sampling_test)