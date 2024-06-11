#include "example.hpp"
#include <greeter/greeter.hpp>

int main(int argc, char **argv) {
    std::cout << Greeter::greet("World") << std::endl;
    Example::appGreeter("World");
    return 0;
}
