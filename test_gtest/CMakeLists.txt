find_package(GTest REQUIRED)
include(GoogleTest)

find_package(spdlog)

file(GLOB TESTDAYSRC test_day*.cpp)
add_executable(tests_gtest $<TARGET_OBJECTS:aoc2021_objects> tests.cpp ${TESTDAYSRC})
target_link_libraries(tests_gtest PRIVATE project_warnings project_options spdlog::spdlog GTest::gtest GTest::gtest_main)

gtest_discover_tests(tests_gtest)
