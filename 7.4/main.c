/*Write a private version of scanf analogous to minprintf from the previous
section.*/
#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 2000
#define MAXNUM 100
#define MAXS 1000

int readword(char* line, char* save_to, char** line_traverse, int max){
    char* start = *line_traverse;
    char* s = save_to;
    while(isspace(*start)){
        ++start;
    }

    char* end = start;
    while(end - start < max - 1 && *end != '\0'){
        if(isspace(*end)) break;
        *s++ = *end++;
    }

    *s = '\0';
    *line_traverse = end;
    return end - start;

}

int readline(char* s, int max){
    int c;
    int len = 0;
    while(len < max - 1 && (c = getchar()) != '\n' && c != EOF){
        *s++ = c;
        len++;
    }

    if(c == '\n'){
        *s++ = c;
        ++len;
    }

    *s = '\0';
    return len;
}

void minscanf(char* fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    char line[MAXLINE];
    char processed[MAXNUM];
    char* save_to = processed;
    while(readline(line, MAXLINE)){
        char* p = fmt;
        char* line_traverse = line;
        while(*p != '\0'){
            if(*p == '%'){
                switch(*++p){
                    case 'd':
                        readword(line, save_to, &line_traverse, MAXNUM);
                        int* a = va_arg(ap, int*);
                        *a = atoi(save_to);
                        break;
                    case 'e':
                    case 'f':
                    case 'g':
                        readword(line, save_to, &line_traverse, MAXNUM);
                        double* b = va_arg(ap, double*);
                        *b = atof(save_to);
                        break;
                    case 'c':
                        readword(line, save_to, &line_traverse, 1);
                        *va_arg(ap, char*) = *line_traverse++;
                        break;
                    case 's':
                        char* s;
                        s = va_arg(ap, char*);
                        readword(line, s, &line_traverse, MAXS);
                        break;
                }
            }
            ++p;
        }
    }
    va_end(ap);   
}

int main(){
    int a = 0;
    double b = 0;
    char test[MAXLINE];
    minscanf("%f", &b);
    minscanf("%d %f %s", &a, &b, test);
    printf("%d %.2f %s", a, b, test);
}