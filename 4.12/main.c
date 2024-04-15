/*Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.*/
#include<stdio.h>
#define MAX 100

void itoa(int num, char arr[]){
        static int i = 0;
        static int len = 0;
        if(i == 0){
            int num_temp = num;
            while(num_temp/=10){
                ++len;
            }
            ++len;
        }
        if(num < 0){
            arr[i++] = '-';
            num*=(-1);
            i++;
            len++;
        }
        if(num/10){
            itoa(num/10, arr);
        }
        arr[i++] = num%10 + '0';
        if(i == len) arr[i] = '\0';
}


int main(){
    int a = 0;
    scanf("%d", &a);
    char array[MAX];
    itoa(a, array);
    printf("%s", array);
}