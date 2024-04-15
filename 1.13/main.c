/*Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging*/

#include<stdio.h>
#define IN 1
#define OUT 0
int main(){
    int data[8] = {0};
    int c;
    int state = OUT;
    int count = 0;
    while((c = getchar()) != EOF) {
        if((c == ' ' || c == '\t' || c == '\n') && state == IN) {
            state  = OUT;
            if(count >= 8) return -1;
            ++data[count];
            count = 0;
        }
        else if (state == OUT) {
            state = IN;
        }
        if(state == IN) ++count;
    }

    printf("Word length\n");
    for(int i = 1; i < 8; ++i) {
        printf("%11d ", i);
        for(int j = 1; j <= data[i]; ++j) {
            printf("=");
        }
        printf("%d \n", data[i]);
    }
}