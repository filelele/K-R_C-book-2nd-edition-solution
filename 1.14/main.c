/*Write a program to print a histogram of the frequencies of different characters
in its input.*/
#include<stdio.h>

int main(){
    int c;
    int data[4] = {0};
    while((c = getchar()) != EOF) {
        if(c >= '0' && c <='9') ++data[0];
        else if((c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A')) ++data[1];
        else if(c == '\t' || c == ' ' || c== '\n' || c == '\b') ++data[2];
        else ++data[3];
    }

    for(int i = 0; i <= 3; ++i) {
        if(i == 0) printf("Digit    ");
        if(i == 1) printf("Alphabet ");
        if(i == 2) printf("Spacing  ");
        if(i == 3) printf("Other    ");
        for(int j = 1; j <= data[i]; ++j) {
            printf("+");
        }
        printf(" %d\n", data[i]);
    }
}