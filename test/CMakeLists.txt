find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE project_warnings project_options GTest::gtest GTest::gtest_main)

gtest_discover_tests(tests)
