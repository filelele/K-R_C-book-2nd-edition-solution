/*Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.*/

#include<stdio.h>
#define MAX 1000
void lower(char s[MAX]){
    for(int i = 0; s[i] != '\0'; ++i){
        s[i] += (s[i]<='Z' && s[i]>= 'A')? 'a' - 'A': 0;
    }
}

int main(){
    char s[]="abc ABCD";
    lower(s);
    printf("%s", s);
}