/*Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define LINES 100
#define MAXLINE 1000

char buffer[100000];
char* bufferp = buffer;

char* alloc(int n){
    if(buffer + 40000 - bufferp >= n){
        bufferp += n;
        return bufferp - n;
    }else{
        printf("Not enough memory\n");
        return NULL;
    }
}

char* lines[LINES];

int getline(char* s){
    int len;
    int c;
    for(len = 0; len < MAXLINE - 1 && (c = getchar()) != EOF; ++len){
        *(s++) = c;
        if(c == '\n'){
            ++len;
            break;
        }
    }

    if(c == EOF) return len;
    
    *s = '\0';
    return len;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("missing or too much arguments\n");
        return -2;
    }
    
    
    int last_n;

    if(*argv[1] == '-' && isdigit(*(argv[1] + 1))){
        last_n = (-1)*atoi(argv[1]);
    }else{
        printf("Invalid argument\n");
        return -1;
    }
    
    char temp[MAXLINE];

    int line_count = 0;
    while(getline(temp) > 0 && line_count < LINES){
        lines[line_count] = alloc(strlen(temp) + 1);
        strcpy(lines[line_count], temp);
        line_count++;
    }
    
    lines[line_count] = NULL;

    if(last_n > line_count){
        printf("required number of lines exceed maximum lines\n");
        return -3;
    }

    for(int i = 1; i <= last_n; ++i){
        printf("Line %d: %s\n", i, lines[line_count-i]);
    }

    return 0;
}