/*Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.*/

/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?*/

/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_TAB 4
#define MAXLINE 1000
#define MAX 4000

char detabstr[MAX];
char* detab(char* a, int tab){
    char* temp = detabstr;
    while(*a != '\0'){
        if(*a != '\t') *(temp++) = *(a++);
        else{
           for(int i = 0; i < tab; ++i){
            *(temp++) = ' ';
           }
           ++a; 
        }
    }
    *temp = '\0';
    return detabstr;
}


char entabstr[MAX];
char* entab(char* a, int tab){
    int count = 0;
    char* temp = entabstr;
    while(*a != '\0'){
        count = 0;
        if(*a != ' ') *(temp++) = *(a++);
        else{
            while(*a == ' '){
                ++count;
                ++a;
            }
            printf("%d\n", count);
            int tabs = count/tab;
            int spaces = count - tabs;

            for(int i = 0; i < tabs; ++i){
                *(temp++) = '\t';
            }

            for(int i = 0; i < spaces; ++i){
                *(temp++) = ' ';
            }
        }
    }
    *temp = '\0';
    return entabstr;
}

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
    char s[MAXLINE];
    char* s_after;
    int index = 1;
    while(getline(s)){
        if(index <= argc - 1){
            s_after = entab(s, atoi(argv[index++]));
        }else{
            s_after = entab(s, DEFAULT_TAB);
        }
        printf("\n%s\n", s_after);
    }
}