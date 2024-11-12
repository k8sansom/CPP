#include "PMergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> inputVec;
    if (!parseInput(argc, argv, inputVec)) {
        return 1;
    }

    // Display the unsorted sequence
    std::cout << "Before: ";
    for (int num : inputVec) std::cout << num << " ";
    std::cout << std::endl;

    // Using two containers
    std::vector<int> vecCopy = inputVec;
    std::deque<int> deqCopy(inputVec.begin(), inputVec.end());

    // Sort and time for vector
    auto startVec = std::chrono::high_resolution_clock::now();
    fordJohnsonSortVector(vecCopy);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vecDuration = endVec - startVec;

    // Sort and time for deque
    auto startDeq = std::chrono::high_resolution_clock::now();
    fordJohnsonSortDeque(deqCopy);
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> deqDuration = endDeq - startDeq;

    // Display the sorted sequence
    std::cout << "After: ";
    for (int num : vecCopy) std::cout << num << " ";
    std::cout << std::endl;

    // Display timing information
    std::cout << "Time to process a range of " << inputVec.size() << " elements with std::vector: " 
              << vecDuration.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << inputVec.size() << " elements with std::deque: " 
              << deqDuration.count() << " us" << std::endl;

    return 0;
}