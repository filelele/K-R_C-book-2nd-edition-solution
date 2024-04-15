/*Modify the pattern finding program of Chapter 5 to take its input from a set of
named files or, if no files are named as arguments, from the standard input. Should the file
name be printed when a matching line is found?*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLINE 1000
char* findPattern(char line[MAXLINE], char pattern[MAXLINE]){
    char* l = line;
    char* p = pattern;
    char* found = NULL;
    while(l < line + MAXLINE && *l != *p) ++l;
    if(*l == '\0') return found;

    found = l;
    while(*l != '\0' && *p != '\0' && *l == *p){
        l++;
        p++;
    }

    if(*p == '\0'){
        return found;
    }else return NULL;
}

int patternFile(FILE* fp, char pattern[MAXLINE], FILE* op){
    int line_count = 1;
    char line[MAXLINE];
    int found = 0;
    while(fgets(line, MAXLINE, fp) != NULL){
        if(findPattern(line, pattern) != NULL){
            fprintf(op, "Found \"%s\" at Line %d\n\t%s\n\n", pattern, line_count, line);
            ++found;
        }
        ++line_count;
    }

    return found;
}

int main(int argc, char* argv[]){
    
    char pattern[MAXLINE];
    fputs("\tPattern to find:\n\t", stdout);
    fgets(pattern, MAXLINE, stdin);
    pattern[strlen(pattern) - 1] = '\0';
    fputs("\n\n", stdout);

    if(argc == 1){
        char line[MAXLINE];
        while(fgets(line, MAXLINE, stdin) != NULL){
            if(findPattern(line, pattern) != NULL) printf("Found\n");
            printf("\n");
        }
    }else{
        while(--argc > 0){
            FILE* fp = fopen(*++argv, "r");
            fprintf(stdout, "Finding \"%s\" in %s . . .\n\n", pattern, *argv);
            int found = patternFile(fp, pattern, stdout);
            if(!found) fprintf(stdout, "%s: Not found here\n", *argv);
            fputs("\n\n\n", stdout);
        }
    }
}