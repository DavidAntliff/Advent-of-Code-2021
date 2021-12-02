#pragma once
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
auto read_values_from_stdin() {
    std::vector<T> values;
    for (std::string line; std::getline(std::cin, line); ) {
        values.push_back(std::stoi(line));
    }
    return values;
}

template <typename T>
void write_to_stdout(const std::vector<T> & v) {
    std::ranges::copy(v, std::ostream_iterator<T>(std::cout, "\n"));
}
