#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        Array<int> intArray(5);

        // Modify elements of intArray
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }
        // Test copy constructor
        Array<int> copiedArray(intArray);

        // Modify the copied array to ensure it doesn't affect the original
        copiedArray[1] = 999;
        std::cout << "After modifying copiedArray[1] to 999:" << std::endl;
        std::cout << "copiedArray[1]: " << copiedArray[1] << std::endl;
        std::cout << "intArray[1]: " << intArray[1] << std::endl;

        // Test assignment operator
        Array<int> newArr;
		newArr = copiedArray;

        // Modify the assigned array to ensure it doesn't affect the original
        newArr[4] = 888;
        std::cout << "After modifying assignedArray[4] to 888:" << std::endl;
        std::cout << "assignedArray[4]: " <<  newArr[4] << std::endl;
        std::cout << "copiedArray[4]: " << copiedArray[4] << std::endl;

        // Test out of bounds access (should throw an exception)
        newArr[10] = 87654; // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}