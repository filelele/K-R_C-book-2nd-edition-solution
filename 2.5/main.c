/*Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)*/
#include<stdio.h>
#define MAX 1000
int any(char s1[MAX], char s2[MAX]){
    int i = 0 ;
    for(;s1[i] != '\0'; ++i){
        for(int j = 0;s2[j] != '\0'; ++j){
            if(s1[i] == s2[j]) return i;
        }
    }

    return -1;
}

int main(){
    char s[] = "con cac";
    char s2[] = "ab";
    printf("%d", any(s, s2));
}