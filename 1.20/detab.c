/*Write a program Detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?*/

#include<stdio.h>

#define TAB 4

void main(){
    int c;
    while((c = getchar()) != EOF) {
        if(c == '\t'){
            for(int i = 0; i < TAB; ++i){
                putchar(' ');
            }
        }
        printf("%c", c);
    }
}

/*n should be EXTERNAL variable to be easy modified in runtime, 
while a symbolic parameter is also good and offer better security (cannot changed in runtime)*/