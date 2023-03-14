#include "example.h"

#include <iostream>

void example_lib::some_exported_call(void) {
    std::cout << "The exported call...has been called." << std::endl;
}
