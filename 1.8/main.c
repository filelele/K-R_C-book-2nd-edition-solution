//write a program to count blanks, tabs and newlines

#include<stdio.h>

int countBlank () {
    int c;
    int bc = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ') ++bc;
    }
    return bc;
}

int countTab () {
    int c;
    int tc = 0;
    while((c = getchar()) != EOF) {
        if(c == '\t') ++tc;
    }
    return tc;
}

int countNewline () {
    int c;
    int nl = 0;
    while((c = getchar()) !=EOF) {
        if(c == '\n') ++nl;
    }
    return nl;
}

int main (){
    int b, t, newl; 
    b = countBlank();
    rewind(stdin);
    t = countTab();
    rewind(stdin);
    newl = countNewline();
    rewind(stdin);
    printf("%d %d %d", b, t, newl);
    return 0;
}