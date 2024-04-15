/*Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)*/

#include<stdio.h>
#define MAX 1000

char fixArrayParenthesis[MAX];
char fixArrayBracket[MAX];
char fixArrayBrace[MAX];

void fixParenthesis()

int getline(char s[MAX]){
    int c;
    int i;
    for(i = 0 ; i<MAX && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}


