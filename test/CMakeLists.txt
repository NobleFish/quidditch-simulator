#-------------------
# Test
#-------------------
cmake_minimum_required(VERSION 3.9)
find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TESTSOURCE "../src/[!main]*.cpp")
file(GLOB testfiles "[!TestTemplate]*.cpp")
foreach(file ${testfiles})
    get_filename_component(_test_name ${file} NAME_WE)
    add_executable(${_test_name} ${file} ${TESTSOURCE})
    target_link_libraries(${_test_name} GTest::GTest GTest::Main)
    gtest_discover_tests(${_test_name})
endforeach()