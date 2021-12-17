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

std::vector<int> sum_sliding_window(const std::vector<int> & input, unsigned long length=3) {
    std::vector<int> result (input.size() - length + 1);
    assert(input.size() >= length);
    auto begin = input.begin();
    auto end = input.end() - static_cast<long>(length) + 1;
    auto ot = result.begin();
    for (auto it = begin; it != end; ++it) {
        *ot = std::accumulate(it, it + static_cast<long>(length), 0);
        ++ot;
    }
    //::write_to_stdout(result);
    return result;
}

namespace {
    void part1() {
        spdlog::info("Part 1");

        auto input = read_values_from_stdin<int>();

        std::cout << count_increases(input) << std::endl;
    }

    void part2() {
        spdlog::info("Part 2");

        auto input = read_values_from_stdin<int>();
        auto window_sums = sum_sliding_window(input, 3);
        std::cout << count_increases(window_sums) << std::endl;
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
