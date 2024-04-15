//Revise the longest-string program for it to printout the leng of arbitrary input lines, and as much as possible of the text

/*
#include <stdio.h>
#define MAXLINE 1000 // maximum input line length 
int getline(char line[], int maxline);
void copy(char to[], char from[]);
print the longest input line
main()
{
    int len; // current line length 
    int max; // maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here 
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
        max = len;
        copy(longest, line);
    }
    if (max > 0) //there was a line
        printf("%s", longest);
    return 0;
}
// getline: read a line into s, return length 
int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
}
    s[i] = '\0';
    return i;
}
// copy: copy 'from' into 'to'; assume to is big enough 
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
*/

#include <stdio.h>
#define MAXLINE 1000 // maximum input line length 
// getline: read a line into s, return length 
int readline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim - 1 && (c=getchar())!=EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') s[i++] = '\n';
    s[i] = '\0';
    return i;
}

//print the longest input line
int main()
{
    int len; // current line length 
    char line[MAXLINE]; // current input line
    int longest = 0;
    while((len = readline(line, MAXLINE)) > 0){
        if(len > longest) longest = len;
        printf("length:%d\nstring:%s\n\n", len, line);
    }

    printf("the longest string length: %d\n", longest);
    return 0;
}
