cmake_minimum_required(VERSION 3.20)

project(DroneTelemetry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    telemetry
    src/telemetry_simulator.cpp
)

target_include_directories(
    telemetry
    PUBLIC
    src
)

add_library(
    safety_monitor
    src/safety_monitor.cpp
)

target_include_directories(
    safety_monitor
    PUBLIC
    src
)

add_executable(
    drone_monitor
    src/main.cpp
)

target_link_libraries(
    drone_monitor
    telemetry
    safety_monitor
)

enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
    safety_tests
    tests/test_safety_monitor.cpp
)

target_link_libraries(
    safety_tests
    telemetry
    safety_monitor
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(safety_tests)
