/*Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.*/

#include<stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0
//getline only

int state = OUT;

int getline(char s[MAXLINE]){
    int c;
    int i = 0;
    while(i < MAXLINE && (c = getchar()) != EOF && c != '\n'){
        s[i] = c;
        ++i;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
}

void rmMultiLCom(char s[MAXLINE]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){
        if(s[i] == '/' && s[i+1] == '*'){
            state = IN;
        }

        if(s[i] == '*' && s[i+1] == '/'){
            s[i] = ' ';
            s[i+1] = ' ';
            i+=2;
            state = OUT;
        } 

        if(state == IN) s[i] = ' ';
    }
}

void rmOnelineCom(char s[MAXLINE]){
    for(int i = 0; s[i] != '\0'; ++i){
        if(s[i] == '/' && s[i+1] == '/'){
            s[i] = '\0';
            break;
        }
    }
}

int main(){
    int len = 0;
    char cline[MAXLINE];
    while((len = getline(cline)) > 0) {
        rmMultiLCom(cline);
        rmOnelineCom(cline);
        printf("%s", cline);
    }
}