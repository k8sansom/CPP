#include "iter.hpp"
#include <iostream>
#include <limits>

template <typename T>
void square(T& element) {
    std::cout << element * element << std::endl;
}

template <typename T>
void increment(T& element) {
    element++;
	std::cout << element << std::endl;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, -37, 4, 5};
    iter(intArray, 5, square<int>);

    // Test with an array of floats
    float floatArray[] = {1.34f, 2.1888f, 3.5f, 894.3789f, -5.7f, -std::numeric_limits<float>::infinity()};
    iter(floatArray, 6, increment<float>);

    return 0;
}