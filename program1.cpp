#include <iostream>
#include <fcntl.h>      // For O_* constants
#include <sys/mman.h>   // For shm_open, mmap, etc.
#include <unistd.h>     // For close
#include <cstring>      // For memset
#include <fstream>
#include <cstdlib>      // For system()

int main() {
    const char* shm_name = "/my_shm";  // Name of the shared memory object
    const size_t shm_size = sizeof(int);

    // Create and open a shared memory object
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Error creating shared memory object" << std::endl;
        return EXIT_FAILURE;
    }

    // Set the size of the shared memory object
    if (ftruncate(shm_fd, shm_size) == -1) {
        std::cerr << "Error setting size of shared memory object" << std::endl;
        return EXIT_FAILURE;
    }

    // Map the shared memory object
    int* shared_mem = static_cast<int*>(mmap(nullptr, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (shared_mem == MAP_FAILED) {
        std::cerr << "Error mapping shared memory object" << std::endl;
        return EXIT_FAILURE;
    }

    // Write a value to the shared memory
    *shared_mem = 42;

    // Print the address and value
    std::cout << "Shared memory address: " << shm_name << std::endl;
    std::cout << "Value: " << *shared_mem << std::endl;

    // Write the shared memory object name to a file for `program2` to read
    std::ofstream outfile("memory_info.txt");
    if (outfile.is_open()) {
        outfile << shm_name << std::endl;
        outfile.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
        return EXIT_FAILURE;
    }

    // Clean up
    munmap(shared_mem, shm_size);
    close(shm_fd);

    // Call program2
    std::cout << "Calling program2..." << std::endl;
    int ret = system("./program2");
    if (ret == -1) {
        std::cerr << "Error calling program2" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "exiting  program1..." << std::endl;
    return 0;
}
