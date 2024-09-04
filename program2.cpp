#include <iostream>
#include <fcntl.h>      // For O_* constants
#include <sys/mman.h>   // For shm_open, mmap, etc.
#include <unistd.h>     // For close
#include <fstream>

int main() {
    const size_t shm_size = sizeof(int);
    std::string shm_name;

    // Read the shared memory object name from the file
    std::ifstream infile("memory_info.txt");
    if (infile.is_open()) {
        std::getline(infile, shm_name);
        infile.close();
    } else {
        std::cerr << "Unable to open file for reading" << std::endl;
        return EXIT_FAILURE;
    }

    // Open the shared memory object
    int shm_fd = shm_open(shm_name.c_str(), O_RDONLY, 0666);
    if (shm_fd == -1) {
        std::cerr << "Error opening shared memory object" << std::endl;
        return EXIT_FAILURE;
    }

    // Map the shared memory object
    int* shared_mem = static_cast<int*>(mmap(nullptr, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0));
    if (shared_mem == MAP_FAILED) {
        std::cerr << "Error mapping shared memory object" << std::endl;
        return EXIT_FAILURE;
    }

    // Print the value from the shared memory
    std::cout << "Read address: " << shm_name << std::endl;
    std::cout << "Read value (hex): 0x" << std::hex << *shared_mem << std::endl;
    std::cout << "Read value (decimal): " << std::dec << *shared_mem << std::endl;
    std::cout << "exit pgroam 2: " << std::endl;
    // Clean up
    munmap(shared_mem, shm_size);
    close(shm_fd);

    return 0;
}
