/*As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/
#include<stdio.h>
#include<ctype.h>
#define MAXBUF 100
int buffer[MAXBUF];
int bufp = 0;
#undef getch
#undef ungetch

int getch(){
    return bufp > 0? buffer[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= MAXBUF){
        printf("Buffer overflow\n");
    }else buffer[bufp] = c;
}

int getint(int* a){
    int c;
    int sign = 1;// default to positive
    while(isspace(c = getch())) ;

    if(!isdigit(c) && c != '+' && c != '-'){
        *a = 0;
        return 0;//return 0 to stop the loop if something wrong appear in the input
    }

    if(c == '+' || c == '-'){
        sign = (c == '-')? -1 : 1;
        c = getch();
    }

    if(isdigit(c)){
        *a = 0;
        for(;isdigit(c); c = getch()){
            *a = *a*10 + (c - '0');
        }
        *a*=sign;
    }

    if(c != EOF){
        ungetch(c);
    }

    return c;//return an EOF to signal the end, or return whatever to continue the loop
}

int main(){
    int arr[MAXBUF];
    int type;
    int i;
    for(i = 0; (type = getint(&arr[i])) != EOF && i < MAXBUF && type != 0; ++i){
        ;
    }

    for(int j = 0; j < i; j++){
        printf("%d ", arr[j]);      
    }
    printf("\narray length: %d", i);
  
  
}