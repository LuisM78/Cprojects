#include <stdio.h>

int main() {
    int a = 1 ;

    switch (a) {
        case 1:
            printf("One\n");
        case 2:
            printf("Two\n");
            break;
        default:
            printf("Other\n");
    }

    return 0;
}

/*
PS>.\day1_swictch_withoutbreaks.exe
One
Two
*/
