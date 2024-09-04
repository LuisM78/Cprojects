#include <stdio.h>

int main() {
    int i = 0;  // Initialize the loop variable

    // Do-while loop to print numbers from 0 to 9
    do {
        printf("%d ", i);
        i++;  // Increment the loop variable
    } while (i < 10);
    printf("\n");

    return 0;
}

/*
PS>.\day1_dowhileloop.exe
0 1 2 3 4 5 6 7 8 9
*/