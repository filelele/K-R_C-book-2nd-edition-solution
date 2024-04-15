/*Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?*/
//I (RE)WROTE THIS ONE FROM START
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAXBUF 100000
#define MAXLINE 5000
#define MAXLINES 20

char allocbuf[MAXBUF];
char* allocp = allocbuf;

char* alloc(int a){
    if(allocbuf + MAXBUF - allocp >= a){
        allocp += a;
        return allocp - a;
    }else{
        printf("Out of dynamic memory\n");
        return NULL;
    }
}

void afree(char* p){
    if(p >= allocbuf && p < allocp) allocp = p;
    else printf("WTF\n");
}

int getline(char* s){
    int count = 0;
    printf("\nGet line: ");
    while(count < MAXLINE - 1 && (*s = getchar()) != '\n' && (*s) != EOF){
        ++s;
        ++count;
    }

    if(*s != EOF) count++;

    *(++s) = '\0';
    return count;
}

char* lines[MAXLINES];

int readlines(char** lines){
    static char line[MAXLINE];
    char** p = lines;
    while(getline(line)){
        if(p < lines + MAXLINES){
            *p = alloc(strlen(line) + 1);
            strcpy(*p, line);
            p++;
        }else {
            printf("CANNOT READ MORE LINES\n");
            break;
        }
    }

    return p - lines;
}

void writelines(char* lines[MAXLINES], int nlines){
    printf("Will writelines: \n");
    for(int i = 0; i < nlines; ++i){
        printf("%s\n", lines[i]);
    }
}

void swap(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char* a[MAXLINES], int low, int high){
    int i,j;
    for(i = low -1, j = low; j < high; ++j){
        if(strcmp(a[j], a[high]) <= 0) swap(&a[++i], &a[j]); 
    }
    swap(&a[++i], &a[high]);
    return i; 
}

void qsort(char** a, int low, int high){
    if(low < high){
        int point = partition(a, low, high);
        qsort(a, low, point - 1);
        qsort(a, point + 1, high);
    }
}


int main(){
    double time_used;
    clock_t start = clock(), end;
    int nlines = readlines(lines);
    writelines(lines, nlines);
    printf("Sorting Lines\n\nResult\n");
    qsort(lines, 0, nlines - 1);
    writelines(lines, nlines);
    end = clock();
    time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("%g", time_used);
    return 0;
}

