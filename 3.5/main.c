/*Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/

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

void itob(int n,char s[],int b){
    int flag = 0;
    int sign = 1;
    int i = 0;
    //handle 2 complement overflow when remove sign from INT_MIN
    if(n == INT_MIN){
        ++n;
        flag = 1;
    }

    //negative must temporarily turn to positive to process
    if(n < 0){
        n = -n;
        sign = -1;
    }
    
    char temp;
    do{                     //do at least once in case it is a zero
        int remainder = n%b;
        if(remainder<=9 && remainder >= 0){
            temp = remainder + '0';
        } else {
            switch(remainder){
                case 10:
                    temp = 'A';
                    break;
                case 11:
                    temp = 'B';
                    break;
                case 12:
                    temp = 'C';
                    break;
                case 13:
                    temp = 'D';
                    break;
                case 14:
                    temp = 'E';
                    break;
                case 15:  //assume the highest is base-16
                    temp = 'F';
                    break;
            }
        }
        s[i++] = temp;
        n/=b;
    }while(n > 0);
    if(sign == -1) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    if(flag == 1){
        s[i++] = '-';
        s[i++] = '1';
        s[i] = '\0';
    }
}

int main(){
    char s[100];
    itob(INT_MIN, s, 16);
    printf("%s", s);
}