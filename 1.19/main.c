//Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

#include<stdio.h>
#define MAXLINE 1000
int readline(char s[MAXLINE]) {
    int c;
    int i;
    for(i = 0 ; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[MAXLINE], int length){
    int i;
    for(i = 0; i < length - 1 - i; ++i){
        char c = s[length - 1 - i];
        s[length - 1 - i] = s[i];
        s[i] = c;
    }
}

int main(){
    int len;
    char line[MAXLINE];
    while((len = readline(line)) > 0) {
        reverse(line, len);
        printf("%s\n", line);
    }
}