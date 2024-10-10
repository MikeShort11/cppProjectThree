#include <iostream>
#include "bits.h"

int main() {
    Bits b; // Default constructor
    std::cout << "Initial bits: " << b << std::endl;

    // Test setting bits
    b.set(0);
    b.set(1);
    std::cout << "After setting bits 0 and 1: " << b << std::endl;

    // Test checking bits
    std::cout << "Bit at position 0: " << b.at(0) << std::endl; // Should be 1
    std::cout << "Bit at position 1: " << b.at(1) << std::endl; // Should be 1
    std::cout << "Bit at position 2: " << b.at(2) << std::endl; // Should be 0

    // Test resetting a bit
    b.reset(1);
    std::cout << "After resetting bit 1: " << b << std::endl;

    // Test toggling a bit
    b.toggle(0);
    std::cout << "After toggling bit 0: " << b << std::endl; // Should be 0
    b.toggle(2);
    std::cout << "After toggling bit 2: " << b << std::endl; // Should be 4 (100)

    // Test setting all bits
    b.set();
    std::cout << "After setting all bits: " << b << std::endl;

    // Test resetting all bits
    b.reset();
    std::cout << "After resetting all bits: " << b << std::endl;

    // Test assigning a value
    b.assign(15); // Binary: 1111
    std::cout << "After assigning value 15: " << b << std::endl;

    // Test counting ones and zeroes
    std::cout << "Number of ones: " << b.ones() << std::endl; // Should be 4
    std::cout << "Number of zeroes: " << b.zeroes() << std::endl; // Should be 60 (assuming 64 bits)

    // Test shifting bits
    b.shift(1); // Shift right by 1
    std::cout << "After shifting right by 1: " << b << std::endl;

    b.shift(-2); // Shift left by 2
    std::cout << "After shifting left by 2: " << b << std::endl;

    // Test rotating bits
    b.rotate(3); // Rotate right by 3
    std::cout << "After rotating right by 3: " << b << std::endl;

    b.rotate(-1); // Rotate left by 1
    std::cout << "After rotating left by 1: " << b << std::endl;

    return 0;
}

