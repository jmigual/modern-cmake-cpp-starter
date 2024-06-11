#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>
#include <iostream>

namespace Example {
    inline void appGreeter(std::string name) {
        std::cout << "Hello " << name << " from the app greeter!\n";
    }
}

#endif