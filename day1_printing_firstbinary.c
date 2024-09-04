#include <stdio.h>

void print_8bin(unsigned char n){
    printf(" %d ", n); 
    for(int i = 7;i>=0;i--){
        printf("%d",(n>>i)&1 );
        if(i%4==0){
            printf(" ");
        }
    }
    printf("\n");
}

int main(){
    for (int i = 0; i<=15;i++){
        print_8bin(i);

    }
    return 0;
}

/*
 0 0000 0000 
 1 0000 0001
 2 0000 0010
 3 0000 0011
 4 0000 0100
 5 0000 0101
 6 0000 0110
 7 0000 0111
 8 0000 1000
 9 0000 1001
 10 0000 1010
 11 0000 1011
 12 0000 1100
 13 0000 1101
 14 0000 1110
 15 0000 1111
*/