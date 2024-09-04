#include <stdio.h>

int main() {
    int number = -3;

    if (number > 0) {
        printf("The number is positive\n");
    } else if (number < 0) {
        printf("The number is negative\n");
    } else {
        printf("The number is zero\n");
    }

    return 0;
}


/*
PS>.\day1_ifthen_check.exe
The number is negative

*/