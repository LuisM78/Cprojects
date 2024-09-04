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