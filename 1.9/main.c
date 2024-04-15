//write a program to copy its input to its output, replace each string of one or more blanks by a single blank
#include<stdio.h>

int main () {
    int i, d;
    while((i = getchar())!= EOF) {
        printf("%c", i);
        if(i == ' ') {
            while((d = getchar()) == ' ') ;
            printf("%c" , d);
        }
    }
}