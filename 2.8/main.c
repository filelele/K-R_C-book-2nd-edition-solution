/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/

#include<stdio.h>

int rightrot(int x,int n){
    int count = 0;
    while(count < n){
        int shifted_bit = 0;
        if(x & 1 == 1)
            shifted_bit = 1;
        else shifted_bit = 0;
        
        x = x >> 1;
        if(shifted_bit == 1)
            x = x^ ((~0)<<(sizeof(int)*8 - 1));
        ++count;
    }
    return x;
}

int main(){
    int a = 64;
    int b = rightrot(a,4);
    printf("%d", b);
}