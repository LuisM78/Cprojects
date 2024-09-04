#include <stdio.h>

int main(){
 int a = 10;
 int b = 20;
 int c = 5;
 int d = 7;
 printf("a %d + b %d = %d \n",a,b,a+b);
 printf("modulo operation a %% b = %d, a is %d and be is %d \n",a%b,a,b);// 10%20= 10
 printf("modulo operation b %% a = %d, a is %d and be is %d \n",b%a,b,a);//20%10 = 0
 printf("modulo operation a %% c = %d, a is %d and c  is %d \n",a%c,a,c);//10%5 = 0
 printf("modulo operation a %% d = %d, a is %d and d  is %d \n",a%d,a,d);//10%7  = 3
 return 0;

}


/*  



- **Arithmetic Operators:** `+`, `-`, `*`, `/`, `%`
  ```c
  int sum = 10 + 5; // 15
  ```

- **Logical Operators:** `&&`, `||`, `!`
  ```c
  if (a > 0 && b < 10) { do something  } 
   */
  
