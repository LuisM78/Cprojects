#include <stdio.h>

int main() {
    int a = 2;  // You can change this value to test different cases

    switch (a) {
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        default:
            printf("Other\n");
            break;
    }

    return 0;
}

/*
PS>.\day1_switch.exe
Two
*/