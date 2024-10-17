#include <iostream>
#include "Serializer.hpp"

int	main(void) {
    // Create a Data structure instance dynamically
    Data* originalData = new Data(42, 'A', 3.14f);

    // Serialize the Data pointer
    uintptr_t serializedData = Serializer::serialize(originalData);

    // Deserialize the uintptr_t back to Data pointer
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Output results
    std::cout << "Original Data: " << originalData->number << ", " 
              << originalData->character << ", " << originalData->decimal << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->number << ", " 
              << deserializedData->character << ", " << deserializedData->decimal << std::endl;

    // Check if original pointer and deserialized pointer are the same
    if (originalData == deserializedData) {
        std::cout << "Success! The original pointer and deserialized pointer are the same." << std::endl;
    } else {
        std::cout << "Error! The pointers do not match." << std::endl;
    }

    // Clean up
    delete originalData;

    return 0;
}