#include <stdio.h>

int main(){

    int a = 10;
    float b = 3.14 ;
    char c = 'A';
    #define pi 3.141516
    const int MAX = 100;


    printf("the value of a is %d is and int \n",a);
    printf("The calue of b is %0.5f is a float \n",b) ;
    printf("the value of char c is %c \n",c);
    printf("the value of pi is %0.8f and is constant\n",pi); 
    printf("the value of MAX is an int constant is %d and is constant\n",MAX); 

    return 0;

}

/*
- **Constants:** Constants are fixed values that cannot be changed during program execution. Use `#define` for constants or `const` keyword.
  ```c
  #define PI 3.14159
  const int MAX = 100;
  */