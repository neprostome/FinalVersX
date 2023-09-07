cmake_minimum_required(VERSION 3.23)
project(lab11)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab11 main.cpp)

# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Enable testing for the project
enable_testing()

# Add the test source files
add_executable(Tests
        Tests.cpp
        )

# Link the Google Test library to the test executable
target_link_libraries(Tests
        PRIVATE
        gtest_main
        )

# Add the test executable as a test
add_test(
        NAME
        Tests
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/Tests
)