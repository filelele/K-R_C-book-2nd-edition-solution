/*Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(void** a, void** b){
    void* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(void* arr[], int low, int high, int(*compare)(void* a, void* b), int reverse){
    int i = low - 1;
    void* pivot = arr[high];

    for(int j = low; j < high; j++){
        if(compare(arr[j], pivot)*(reverse) < 0){
            swap(&arr[++i], &arr[j]);
        }
    }

    swap(arr[++i], arr[high]);
    return i;
}

int numcmp(char* s1, char* s2){
    float a = atof(s1);
    float b = atof(s2);

    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

void myqsort(void* arr[], int low, int high, int(*compare)(void* a, void* b), int reverse){
    if(low >= high) return;
    int pivot = partition(arr, low, high, compare, reverse);

    myqsort(arr, low, pivot - 1, compare, reverse);
    myqsort(arr, pivot + 1, high, compare, reverse);
}

#define MAXLINE 100
#define ONELINE 1000
char* lines[MAXLINE];

char memorybuf[100000];
char* memoryp = memorybuf;

char* alloc(int n){
    if(memorybuf+100000 - memoryp >= n){
        memoryp += n;
        return memoryp - n;
    }else{
        return NULL;
    }
}

void freem(char* a){
    if(a>= memorybuf && a < memorybuf + 100000) memoryp = a;
}

int getline(char** s){
    *s = alloc(ONELINE);
    char* temp = *s;
    int c;
    int count;
    for(count = 0; count < ONELINE && (c = getchar()) != '\n' && c != EOF; ++count, ++temp){
        *temp = c;
    }

    if(c == '\n'){
        ++count;
        *(++temp) = c;
        *(++temp) = '\0';
    }
    if(c == EOF) return 0;
    return count;
}

int readlines(){
    int linecount = 0;
    char** temp = lines;
    while(getline(temp)){
        linecount++;
        ++temp;
    }

    return linecount;
}

void writelines(int linecount){
    static int paragraph = 1;
    printf("\n#%d\n", paragraph);
    for(int i = 0; i < linecount; ++i){
        printf("\t%s\n", lines[i]);
    }
    ++paragraph;
}

int main(int argc, char* argv[]){
    int reverse = 1;
    int numeric_sort = 0;

    for(int i = 1; i < argc; ++i){
        if(*argv[i] == '-'){
            switch(*(argv[i]+1)){
                case 'r':
                    reverse = -1;
                    continue;
                case 'n':
                    numeric_sort = 1;
                    continue;
            }
        }else{
            printf("Unknown argument(s)\n");
            break;
        }
    }

    int line_count = 0;
    int (*compare_method[])(char* a, char* b) = {strcmp, numcmp};

    while(line_count = readlines()){
        myqsort(lines, 0, line_count - 1, compare_method[numeric_sort], reverse);
        writelines(line_count);
        freem(lines[0]);
    }

    printf("End");
}

