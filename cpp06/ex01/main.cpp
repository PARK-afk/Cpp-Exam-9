#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data    d;

    d.u = 42;
    d.in= 123.43;
    d.tptr = 'A';

    uintptr_t srz = Serializer::serialize(&d);
    Data *dsrz = Serializer::deserialize(srz);

    d.tptr = 'B';
    std::cout << "Data *'s Memory : " << &d << std::endl;
    std::cout << "uintptr_t's Memory : " << dsrz << std::endl;
    std::cout << "uintptr_t : " << srz << std::endl;
    if (dsrz == &d) {
        std::cout << "Test Case 1: Serialization and deserialization successful." << std::endl;
    } else {
        std::cout << "Test Case 1: Serialization and deserialization failed." << std::endl;
    }
    // Test Case 2: Serialization of NULL Pointer
    {
        Data* nullPtr = NULL;
        uintptr_t serializedNullPtr = Serializer::serialize(nullPtr);
        Data* deserializedNullPtr = Serializer::deserialize(serializedNullPtr);

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "NULLPTR *'s Memory : " << &nullPtr << std::endl;
        std::cout << "DESERIAL's Memory : " << &deserializedNullPtr << std::endl;
        std::cout << "SERIAL's : " << &serializedNullPtr << std::endl;
        
        if (deserializedNullPtr == NULL) {
            std::cout << "Test Case 2: Serialization and deserialization of NULL pointer successful." << std::endl;
        } else {
            std::cout << "Test Case 2: Serialization and deserialization of NULL pointer failed." << std::endl;
        }
    }
    return 0;
}