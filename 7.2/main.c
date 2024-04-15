/*Write a program that will print arbitrary input in a sensible way. As a
minimum, it should print non-graphic characters in octal or hexadecimal according to local
custom, and break long text lines.*/

#include<stdio.h>
#include<stdlib.h>//for strtol
#include<ctype.h>
#define MAXLINE 2000
#define MAXW 15

int readline(char line[], int max){
    int c;
    int len = 0;
    while(len < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF) line[len++] = c;

    if(c == '\n')
        line[len++] = c;

    line[len] = '\0';
    return len;
}

int main(){
    char line[MAXLINE];
    char processed[MAXW];
    while(readline(line, MAXLINE)){
        char* line_traverse = line;
        while(*line_traverse != '\0'){
            if(*line_traverse == '0' && *(line_traverse + 1) =='x' && isdigit(*(line_traverse + 2))){
                line_traverse += 2;//skip non-graphic part to the number part
                int i = 0;
                while(i < MAXW && isdigit(*line_traverse)){
                    processed[i++] = *line_traverse++;
                }
                processed[i] = '\0'; 
                printf("%X", atoi(processed));
                continue;
            }else if(*line_traverse == 'o' && isdigit(*(line_traverse + 1))){
                ++line_traverse;//skip non-graphic part to the number part
                int i = 0;
                while(i < MAXW && isdigit(*line_traverse)){
                    processed[i++] = *line_traverse++;
                }
                processed[i] = '\0'; 
                printf("%o", atoi(processed));
                continue;
            }else putchar(*line_traverse++);
        }
    }


}