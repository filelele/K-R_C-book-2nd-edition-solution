/*Write a program to compare two files, printing the first line where they differ.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h> //for exit()

#define MISSING_FILE 1
#define ERROR_OPEN_FILE 2
#define EXCEED_FILE_LIMIT 3
#define MAXFILE 2
#define MAXLINE 5000

void compareFile(FILE* fp1, FILE* fp2, FILE* op){
    char line1[MAXLINE];
    char line2[MAXLINE];
    char* ptr1 = line1;
    char* ptr2 = line2;

    int line_count = 1;
    while((ptr1 = fgets(line1, MAXLINE, fp1)) != NULL && (ptr2 = fgets(line2, MAXLINE, fp2)) != NULL){
        int cmp = strcmp(line1, line2);
        if(cmp != 0){
            fprintf(op, "Difference found at line %d:\n\n", line_count);
            fprintf(op, "At file 1:\n%s\n", line1);
            fprintf(op, "At file 2:\n%s\n", line2);
            break;
        }

        ++line_count;
    }

    if(ptr1 == NULL) ptr2 = fgets(line2, MAXLINE, fp2);//in case file 1 end of file first, 
                                                //file2 cant get the next line yet, so get it for file2

    if(ptr1 == NULL && ptr2 == NULL){
        fputs("No differece\n", op);
    }else if(ptr1 == NULL && ptr2 != NULL){
        fputs("File 1 ends before File 2, additional lines in File 2:\n", op);
        fprintf(op, "%s", line2);
        while((ptr2 = fgets(line2, MAXLINE, fp2)) != NULL){
            fprintf(op, "%s", line2);
        }
    }else if(ptr1 != NULL && ptr2 == NULL){
        fputs("File 2 ends before File 1, additional lines in File 1:\n", op);
        fprintf(op, "%s", line1);
        while((ptr1 = fgets(line1, MAXLINE, fp1)) != NULL){
            fprintf(op, "%s", line1);
        }
    }
}
int main(int argc, char* argv[]){
    if(argc == 1){
        fprintf(stderr, "%s: What to compare?\n", argv[0]);
        exit(MISSING_FILE);
    }

    if(argc == 2){
        fprintf(stderr, "%s: Compare %s to what . . .?\n", argv[0], argv[1]);
        exit(MISSING_FILE);
    }

    if(argc - 1 > MAXFILE){
        fprintf(stderr, "%s: Exceed supported number of files(%d) to compare\n Passed in (%d) files\n", argv[0], MAXFILE, argc - 1);
        exit(EXCEED_FILE_LIMIT);
    }
    
    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "r");

    compareFile(fp1, fp2, stdout);
}
