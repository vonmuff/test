#include "GreeterLib/GreeterLib.hpp"
#include <iostream>
std::string Greeter::greet() {
    int* SomePtr{NULL};
    return "Hello from the modular greeter library";
}

namespace {
bool should_ignore(std::string name) {
    std::cout << "!111" << std::endl;
  return name == "Bob";
}
}

std::string get_greeting() { return "Hello from the modular greeter library"; }