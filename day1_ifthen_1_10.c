#include <stdio.h>

int main() {
    int number = 7;

    if (number >= 0 && number <= 10) {
        printf("The number is between 0 and 10.\n");
        if (number % 2 == 0) {
            printf("The number is even.\n");
        } else {
            printf("The number is odd.\n");
        }
    } else {
        printf("The number is outside the range of 0 to 10.\n");
    }

    return 0;
}


/*
PS>.\day1_ifthen_1_10.exe 
The number is between 0 and 10.
The number is odd.
*/