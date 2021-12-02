#include <iostream>
#include <vector>
#include <numeric>

#include <spdlog/spdlog.h>

#include "utils.h"

long count_increases(const std::vector<int> & input) {
    auto diff = decltype(input){};

    std::adjacent_difference(std::begin(input), std::end(input), std::back_inserter(diff));
    auto count = std::count_if(std::next(std::begin(diff)), std::end(diff), [&](int x) -> bool { return x > 0; });

    //::write_to_stdout(diff);
    return count;
}

namespace {
    void part1() {
        spdlog::info("Part 1");

        auto input = read_values_from_stdin<int>();

        std::cout << count_increases(input) << std::endl;
    }

    void part2() {
        spdlog::info("Part 2");
    }
}

void day01(int part) {
    spdlog::info("Day 01");
    if (part == 1) {
        ::part1();
    } else if (part == 2) {
        ::part2();
    }
}
