#include <iostream>

int main() {
    int* ptr = new int; // Allocate memory
    *ptr = 10; // Assign value
    std::cout << "Value: " << *ptr << std::endl;


        // Print the value of x
    std::cout << "Value at address of the ptr: " << *ptr << std::endl;

    // Print the address of x
    std::cout << "Address of x: " << ptr << std::endl;



    //delete ptr; // Free memory (commented out)

    return 0;
}
