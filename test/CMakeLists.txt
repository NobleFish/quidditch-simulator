#-------------------
# Test
#-------------------
cmake_minimum_required(VERSION 3.9)
find_package(GTest REQUIRED)
include(GoogleTest)

set(TESTFILES
    unitTests.cpp
    BallTest.cpp
    PlayerTest.cpp
)

file(GLOB TESTSOURCE "../src/[!main]*.cpp")

add_executable(unit_tests ${TESTFILES} ${TESTSOURCE})
target_link_libraries(unit_tests GTest::GTest GTest::Main)
gtest_discover_tests(unit_tests)
