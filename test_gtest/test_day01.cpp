#include <gtest/gtest.h>

extern long count_increases(const std::vector<int> & input);
extern std::vector<int> sum_sliding_window(const std::vector<int> & input, unsigned long length);

class Tests : public ::testing::Test {};



TEST_F(Tests, test_count_increases) {
    std::vector<int> input {
        199,
        200,
        208,
        210,
        200,
        207,
        240,
        269,
        260,
        263};

    EXPECT_EQ(7, count_increases(input));
}

TEST_F(Tests, test_sliding_window) {
    std::vector<int> input {
        199,
        200,
        208,
        210,
        200,
        207,
        240,
        269,
        260,
        263,
    };

    const std::vector<int> expected {
        607,
        618,
        618,
        617,
        647,
        716,
        769,
        792,
    };

    auto actual = sum_sliding_window(input, 3);

    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}

