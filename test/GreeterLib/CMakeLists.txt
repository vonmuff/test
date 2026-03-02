cmake_minimum_required(VERSION 3.23)

find_package(GTest REQUIRED)

add_executable(TestGreeterLib test_GreeterLib.cpp)

target_link_libraries(TestGreeterLib
    PRIVATE
    GreeterLib
    GTest::GTest
    GTest::Main
)
gtest_discover_tests(TestGreeterLib
    PROPERTIES LABELS "library"
)
