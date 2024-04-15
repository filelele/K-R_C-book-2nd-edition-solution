#include<stdio.h>
#define MAX 1000
void forLoopReplace(char s[MAX]){
    int i = 0;
    int c;
    while(i < MAX-1 && (c=getchar())!= EOF && c != '\n'){
        s[i] = c;
        ++i;
    }
    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
}

int main(){

}