#include <stdio.h>

// Function declarations
int add(int a, int b);
int factorial(int n);

int main() {
    // Using the add function
    int sum = add(5, 3);
    printf("Sum: %d\n", sum);

    // Using the factorial function
    int number = 5;
    int result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

/*
PS>.\day1_funcdecla.exe
Sum: 8
Factorial of 5 is 120
*/