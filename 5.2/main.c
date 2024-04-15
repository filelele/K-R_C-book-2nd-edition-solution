/*Write getfloat, the floating-point analog of getint. What type does
getfloat return as its function value?*/

#include<stdio.h>
#include<ctype.h>
#define MAX 100

int buffer[MAX];
int bufp = 0;

int getch(){
    return bufp>0? buffer[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= MAX) printf("Buffer overflow\n");
    else buffer[bufp++] = c;
}

int getfloat(double* a){
    int c;
    int sign = 1;
    while(isspace(c = getch())) ;
    
    if(!isdigit(c) && c != '+' && c != '-'){
        return 0;
    }

    if(c == '+' || c == '-'){
        sign = c == '-'? -1 : 1;
        c = getch();
    }

    for(*a = 0;isdigit(c);c = getch()){
        *a = *a*10 + (c - '0');
    }

    int power = 1;
    if(c == '.'){
        c = getch();
        for(;isdigit(c);c = getch()){
            *a = *a*10 + (c - '0');
            power*=10;
        }
        *a = *a / power;
    }
    
    *a*=sign;

    if(c != EOF){
        ungetch(c);
    }

    return c;
}

int main(){
    double arr[MAX];
    int type;
    int n;
    for(n = 0; n < MAX && (type = getfloat(&arr[n])) != 0 && type != EOF; ++n){

    }

    for(int i = 0; i < n; ++i){
        printf("%.2lf ", arr[i]);
    }
}