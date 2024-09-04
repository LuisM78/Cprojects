#include <iostream>
#include <cstdlib> // For exit() function

int main() {
    // Define the specific address
    uintptr_t address = 0x562659c49eb0;
    
    // Cast the address to an int pointer
    int* p = reinterpret_cast<int*>(address);
    
    // Attempt to read the value at the address
    try {
        std::cout << "Value at address 0x" << std::hex << address << ": " << std::dec << *p << std::endl;
    } catch (...) {
        std::cerr << "Error: Unable to read memory at address 0x" << std::hex << address << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return 0;
}
