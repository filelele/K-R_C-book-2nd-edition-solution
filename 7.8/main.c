/*Write a program to print a set of files, starting each new one on a new page,
with a title and a running page count for each file.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>// for exit

#define MAXLINE 998
#define PAGELINE 30

//exit error code
#define NO_FILE 1
#define ERROR_ACCESS_FILE 2
#define OUTPUTSTREAM stdout
#define ERRORSTREAM stderr
#define SUCCESS 0

int line_count = 0;
int page = 0;

void printNewpage(int page){
    fprintf(OUTPUTSTREAM, "\n\n\tPAGE %d\n\n", page);
}
void printFile(FILE* fp){
    ++page;
    printNewpage(page);
    
    char line[MAXLINE];
    while(fgets(line, MAXLINE, fp) != NULL){
        ++line_count;
        if(line_count > PAGELINE){
            ++page;
            line_count = 1;
            printNewpage(page);
        }
        fprintf(OUTPUTSTREAM, "%2d/%s", line_count, line);
    }
}
int main(int argc, char* argv[]){
    if(argc == 1){
        fprintf(ERRORSTREAM ,"%s: No file?\n\n", *argv);
        exit(NO_FILE);
    }

    FILE* fp;
    while(--argc > 0){
        
        if((fp = fopen(*++argv, "r")) == NULL){
            fprintf(ERRORSTREAM, "%s: Failed to open %s\n\n", argv[0], *argv);
            exit(ERROR_ACCESS_FILE);
        }

        printFile(fp);
    }

    exit(SUCCESS);
}