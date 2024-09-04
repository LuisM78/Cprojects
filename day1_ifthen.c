#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    if (a > b) {
        printf("a is greater than b\n");
    } else {
        printf("b is greater than or equal to a\n");
    }

    return 0;
}

/*
PS>.\day1_ifthen.exe
b is greater than or equal to a
*/