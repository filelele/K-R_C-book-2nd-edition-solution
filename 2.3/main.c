/*Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.*/

#include<stdio.h>
#include<limits.h>
#include<math.h>
#define MAX 1000

int getLength(char hex[MAX]){
    int len = 0;
    while(hex[len]!= '\0'){
        ++len;
    }
    return len;
}
int hexToInt(char hex[MAX], int len){
    int i;
    int sum = 0;
    for(i = len - 1; i>=0 && hex[i] != 'x' && hex[i] != 'X'; --i){
        int dec = 0;
        if(hex[i] <= '9' && hex[i]>= '0'){
            dec = pow(16,(len-1-i)) * (hex[i] - '0');
        }

        switch(hex[i]){
            case 'a': 
                dec = pow(16,(len-1-i)) * 10;
                break;
            case 'b': 
                dec = pow(16,(len-1-i)) * 11;
                break;
            case 'c': 
                dec = pow(16,(len-1-i)) * 12;
                break;
            case 'd': 
                dec = pow(16,(len-1-i)) * 13;
                break;
            case 'e': 
                dec = pow(16,(len-1-i)) * 14;
                break;
            case 'f': 
                dec = pow(16,(len-1-i)) * 15;
                break;
            case 'A': 
                dec = pow(16,(len-1-i)) * 10;
                break;
            case 'B': 
                dec = pow(16,(len-1-i)) * 11;
                break;
            case 'C': 
                dec = pow(16,(len-1-i)) * 12;
                break;
            case 'D': 
                dec = pow(16,(len-1-i)) * 13;
                break;
            case 'E': 
                dec = pow(16,(len-1-i)) * 14;
                break;
            case 'F': 
                dec = pow(16,(len-1-i)) * 15;
                break;
        }

        sum += dec; 
    }

    return sum;
}

int main(){
    char s[] = "0x2F1"; 
    printf("Length: %d\n", getLength(s));
    printf("%ld\n", hexToInt(s, getLength(s)));
    printf("%d", 1+15*16+2*16*16);//check
}