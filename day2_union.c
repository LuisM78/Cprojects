#include <stdio.h>
#include <string.h>

// Define a union for data types
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    // Assign and display integer value
    data.i = 10;
    printf("data.i : %d\n", data.i);

    // Assign and display float value
    data.f = 220.5;
    printf("data.f : %.1f\n", data.f);

    // Assign and display string value
    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    return 0;
}

/*
PS>.\day2_union.exe
data.i : 10
data.f : 220.5
data.str : C Programming
*/