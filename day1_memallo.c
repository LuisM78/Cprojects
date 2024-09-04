#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    // Pointers example
    int a = 10;
    int *p = &a; // Pointer to int holding the address of 'a'

    printf("Value of a: %d\n", a);       // Print value of 'a'
    printf("Value through pointer p: %d\n", *p); // Dereference pointer p to print value of 'a'

    // Dynamic memory allocation example
    int *dynamicArray = (int*)malloc(sizeof(int) * 5); // Allocate memory for 5 integers

    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the allocated memory
    dynamicArray[0] = 10;
    printf("Value at dynamicArray[0]: %d\n", dynamicArray[0]);

    // Free the allocated memory
    free(dynamicArray);

    return 0;
}
/*
PS>.\day1_memallo.exe
Value of a: 10
Value through pointer p: 10
Value at dynamicArray[0]: 10
PS>

*/