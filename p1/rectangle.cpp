#include <iostream>
#include "rectangle.h"
#include <cassert>

// Function to calculate area
void area(float width, float height) {
    // Preconditions
    assert(width > 0 && height > 0);
    // Postcondition: Output area
    std::cout << "Area: " << width * height << std::endl;
}

// Function to calculate perimeter
void perimeter(float width, float height) {
    // Preconditions
    assert(width > 0 && height > 0);
    // Postcondition: Output perimeter
    std::cout << "Perimeter: " << 2 * (width + height) << std::endl;
}
