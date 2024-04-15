/*In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.*/

/*because a n-bit two complement int cannot hold a value that as large as its negative counterpart
|1000....0000| > 0111...1111*/

#include<stdio.h>
#include<limits.h>

int strLength(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        ++i;
    } 
    return i;
}

void reverseStr(char s[]){
    int len = strLength(s);
    int head = 0;
    int tail = len -1;
    for(;head < tail; ++head, --tail){
        int c = s[tail];
        s[tail] = s[head];
        s[head] = c; 
    }
}

void intToA(int n, char s[]){
    int flag = 0;
    if(n == INT_MIN){
        flag = 1;
        ++n;
    }
    
    int i = 0;
    int sign = 1;
    if(n<0){
        n = n*(-1);
        sign = -1;
    }
    
    do{
        s[i] = n%10 + '0'; 
        ++i;
    }while((n /= 10) > 0);

    if(sign == -1) s[i++] = '-';
    if(flag == 1) {
        s[0]++;
    }
    s[i] = '\0';
    reverseStr(s);
}

int main(){
    int t1 = -2323;
    int t2 = 23132;
    int t3 = INT_MIN;
    char s1[10];
    char s2[10];
    char s3[30];
    intToA(t1, s1);
    intToA(t2, s2);
    intToA(t3, s3);
    printf("%s\n%s\n%s", s1, s2, s3);
    printf("\nint min: %d", INT_MIN);
}

