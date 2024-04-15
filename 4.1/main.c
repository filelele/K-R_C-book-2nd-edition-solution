/*Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/

#include<stdio.h>

int getline(char s[], int MAXLINE){
    int c;
    int i = 0;
    while(i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }

    if(c == '\n'){
        s[i++] = '\n';
    }

    s[i] = '\0';
    return i;
}

int strindex(char source[], char pattern[]){
    int i = 0,k = 0,j = 0;
    int pos = -1;
    for(i=0; source[i] != '\0'; ++i){
        for(j = i, k = 0; pattern[k] != '\0' && source[j] == pattern[k]; ++j, ++k){
            ;
        }

        if(pattern[k] == '\0')
        pos = i;
    }
    return pos;
}


int main(){
    char s[1000];
    char p[] = "abc";
    while(getline(s, 1000) > 0){
        printf("%d\n", strindex(s,p));
    }
}
