#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>
#include <sstream>

namespace Example {
    inline std::string appGreeter(std::string name) {
        std::stringstream ss;
        ss << "Hello " << name << " from the app greeter!\n";
        return ss.str();
    }
}

#endif