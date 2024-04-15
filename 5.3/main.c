/*Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(t1,t2) copies the string t2 to the end of t1.*/

#include<stdio.h>
#include<string.h>
#define MAX 1000

static char allocbuf[MAX];
static char* allocp = allocbuf;

char* alloc(int n){
    if(n <= (allocbuf + MAX) - allocp){ //just comprehend allocp as the number of occupied slot
        printf("get %d slots\n", n);
        allocp += n;
        return allocp - n;
    }else return NULL;
}

void afree(char* p){
    if(p>=allocbuf && p < (allocbuf + MAX)){
        allocp = p;
    }
}

char* mstrcat(char* s, char* t){
    int len = strlen(s) + strlen(t);
    char* new = alloc(len+1);
    char* start = new;
    while(*(new++) = *(s++)) ;
    --new;
    while(*(new++) = *(t++)) ;
    *new = '\0';
    return start;
}

int main(){
    char* test = "asadasdbc";
    char* con = "1232433523";
    char* res = mstrcat(test, con);
    printf("%s", res);
    afree(res);
}