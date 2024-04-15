/*Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.*/
#include<stdio.h>
#include<limits.h>

int strLen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){
        ;
    }
    return i;
}

void reverse(char s[]){
    int len = strLen(s);
    int temp;
    for(int head = 0,tail = len -1;head < tail;++head, --tail){
        temp = s[tail];
        s[tail] = s[head];
        s[head] = temp;
    }
}

void itoa(int n, char s[], int w){
    int sign =1;
    int flag = 0;
    
    if(n == INT_MIN) {
        flag =1;
        ++n;
    }
    
    if(n<0){
        n = -n;
        sign = -1;
    }

    int i = 0;
    do{
        s[i++] = n%10 +'0';
    }while((n/=10) > 0);

    if(sign == -1){
        s[i++] = '-';
    }
    if(flag == 1){
        ++s[0];  
    }

    s[i] = '\0';
    int len = strLen(s);
    if(len < w){
        int pad = w - len;
        int j = 0;
        for(j = 0; j < pad; ++j){
            s[i+j] = ' ';
        }
        s[i+j] = '\0';
    }

    reverse(s);
}

int main(){
    char s[30];
    itoa(INT_MIN,s,10);
    printf("%s", s);
}