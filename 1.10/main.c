/*Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.*/
#include<stdio.h>

int main () {
    int c;
    while((c = getchar()) != EOF) {
        if(c == '\t') printf("\\t");
        if(c == '\b') printf("\\b");
        if(c == '\\') printf("\\");
        putchar(c);
    }
}

//not work with input.txt because ascii code of Tab is '9' not '\t'