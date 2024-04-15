//write a program that prints its input one word per line
#include<stdio.h>
#define IN 1
#define OUT 0
int main(){
    int c, state;
    state = OUT;
    while((c=getchar()) != EOF) {
        if(c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            printf("\n");
        }

        if(state == IN) putchar(c);
    }
    
}