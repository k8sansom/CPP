#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>  

// Function to validate and parse input
bool parseInput(int argc, char* argv[], std::vector<int>& inputVec) {
    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(argv[i]);
        if (number <= 0) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        inputVec.push_back(number);
    }
    return true;
}

// Implement the Ford-Johnson merge-insert sort for each container separately
void fordJohnsonSortVector(std::vector<int>& data) {
    // Placeholder for the Ford-Johnson algorithm implementation on vector
    // (implement sorting logic here)
}

void fordJohnsonSortDeque(std::deque<int>& data) {
    // Placeholder for the Ford-Johnson algorithm implementation on deque
    // (implement sorting logic here)
}