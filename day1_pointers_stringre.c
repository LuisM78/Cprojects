#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    printf("Original String: %s\n", str);
    reverse(str);
    printf("Reversed String: %s\n", str);
    return 0;
}

/*
PS>.\day1_pointers_stringre.exe
Original String: Hello, World!
Reversed String: !dlroW ,olleH
*/