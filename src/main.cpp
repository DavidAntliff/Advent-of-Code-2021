#include <functional>
#include <iostream>
#include <charconv>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

static constexpr auto USAGE =
  R"(Advent of Code 2021.

    Usage: aoc2021 [options] <day> <part>

    Options:
        -h, --help    Show help
        -d, --debug   Show debug output
)";

extern void day01(int part);

int main(int argc, const char **argv)
{
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
      { std::next(argv), std::next(argv, argc) },
      true);// show help if requested

    for (auto const &arg : args) {
        std::cout << arg.first << "=" << arg.second << std::endl;
    }

    if (args["--debug"].asBool()) {
        spdlog::set_level(spdlog::level::debug);
    }

    const auto day = static_cast<int>(args["<day>"].asLong());
    const auto part = static_cast<int>(args["<part>"].asLong());
    spdlog::debug("day {}, part {}", day, part);

    switch (day) {
    case 1:
        day01(part);
        break;
    default:
        spdlog::error("Invalid day {}", day);
    };

//    const auto day_s = args["<day>"].asString();
//    const auto part_s = args["<part>"].asString();
//    int day{}, part{};
//    auto [day_ptr, day_ec]{ std::from_chars(day_s.data(), day_s.data() + day_s.size(), day) };
//    auto [part_ptr, part_ec]{ std::from_chars(part_s.data(), part_s.data() + part_s.size(), day) };
//
//    if (day_ec == std::errc() && part_ec == std::errc()) {
//        switch (day) {
//        case 1:
//            day01(part);
//            break;
//        default:
//            spdlog::error("Invalid day {}", day);
//        };
//    } else {
//        spdlog::error("Invalid day {} or part {}", day_s, part_s);
//        return 1;
//    }

    //
    //  //Use the default logger (stdout, multi-threaded, colored)
    //  spdlog::info("Hello, {}!", "World");
    //
    //  fmt::print("Hello, from {}\n", "{fmt}");

    return 0;
}
