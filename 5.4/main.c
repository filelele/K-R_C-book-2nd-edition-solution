/*Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.*/

#include<stdio.h>

int mstrend(char* s, char* t){
    char* ss = s;
    char* st = t;

    while(*(s++)){
        ;
    }
    --s;

    while(*(t++)){
        ;
    }
    --t;

    while(*(s--) == *(t--)) ;
    s+=1;
    t+=1;

    if(t == (st-1)) return 1;
    else return 0;
}

int main(){
    printf("%d", mstrend("con cho", "hcho"));
}