#include <stdio.h>

// Define an enumeration for days of the week
enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main() {
    enum Day today = Wednesday;

    if (today == Wednesday) {
        printf("It's Wednesday!\n");
    }

    return 0;
}
/*
PS>.\day2_enum.exe
It's Wednesday!
PS>
*/