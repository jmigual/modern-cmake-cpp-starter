#include "greeter.hpp"

#include <fmt/format.h>

std::string Greeter::greet(std::string name) {
    return fmt::format("Hello, {}!\n", name);
}

