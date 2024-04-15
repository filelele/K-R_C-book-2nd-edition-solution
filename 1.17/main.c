//Write a program to print all input lines that are longer than 8 characters.

#include<stdio.h>
#define MAXLINE 700
#define MIN_LENGTH 80

int readline(char s[]) {
    int i = 0;
    int c;
    while((c = getchar()) != EOF && c != '\n' && i < MAXLINE ) {
        s[i] = c;
        ++i;
    }
    if(c == '\n') s[i++] = '\n';
    s[i] = '\0';
    return i; 
}

int main(){
    char print[MAXLINE];
    int len = 0;
    while((len = readline(print)) > 0) {
        if(len > 8) printf("%d\n%s\n\n", len, print);
    }
    return 0;
}