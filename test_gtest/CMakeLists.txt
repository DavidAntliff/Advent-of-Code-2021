find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests_gtest tests.cpp)
target_link_libraries(tests_gtest PRIVATE project_warnings project_options GTest::gtest GTest::gtest_main)

gtest_discover_tests(tests_gtest)
