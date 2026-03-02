cmake_minimum_required(VERSION 3.23)

find_package(GTest REQUIRED)

add_executable(TestGreeterApp test_GreeterApp.cpp)

target_link_libraries(TestGreeterApp
    PRIVATE
    GreeterAppLogic
    GTest::GTest
    GTest::Main
)

gtest_discover_tests(TestGreeterApp
    PROPERTIES LABELS "app"
)
