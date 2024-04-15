//Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines

#include<stdio.h>
#define MAXLINE 1000
//this function remove trailing space, copy line from input to string argument, and return line length
int readline(char s[MAXLINE]) {
    int c;
    int i = 0;
    while(i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n' && i < MAXLINE) {
        s[i] = c;
        ++i;
    }
    //add nextline to last position, increase i by 1 to match true line length
    if(c == '\n') {
        s[i] = c;
        ++i;   
    }

    s[i] = '\0';
    if(!i) return 0;
    //remove trailing spaces
    int lastchar;
    for(lastchar = i - 1; (s[lastchar] == ' ' || s[lastchar] == '\t') && lastchar > 0; --lastchar){
        ;
    }
    s[lastchar + 1] = '\0';

    return lastchar + 1;
}

int main(){
    int len;
    char line[MAXLINE];
    int lineCount = 1;
    while((len = readline(line)) > 0) {
        if(line[0] == '\n') continue;
        printf("Line: %d\nLength:%d\nContent:%s\n\n", lineCount, len, line);
        ++lineCount;
    }
}