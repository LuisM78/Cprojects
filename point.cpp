#include <iostream>  // Include the iostream header for input/output operations

int main() {
    int x = 10;         // Define an integer variable x
    int* p = &x;        // Define a pointer p that holds the address of x

    // Print the value of x
    std::cout << "Value of x: " << x << std::endl;

    // Print the address of x
    std::cout << "Address of x: " << p << std::endl;

    // Print the value at the address stored in pointer p
    std::cout << "Value at address p: " << *p << std::endl; // Dereference p

    return 0;
}
