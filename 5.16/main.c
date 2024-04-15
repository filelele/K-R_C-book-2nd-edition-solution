/*Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//tolower() and toupper()

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

    swap(&arr[++i], &arr[high]);
    return i;
}

int numcmp(char* s1, char* s2){
    float a = atof(s1);
    float b = atof(s2);

    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

int lowHighNoDiff(char* s1, char* s2){
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = tolower(*s1);
        char c2 = tolower(*s2);

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }

    return *s1 - *s2;

}

void myqsort(void* arr[], int low, int high, int(*compare)(void* a, void* b), int reverse){
    if(low >= high) return;
    int pivot = partition(arr, low, high, compare, reverse);

    myqsort(arr, low, pivot - 1, compare, reverse);
    myqsort(arr, pivot + 1, high, compare, reverse);
}

int directoryOrder(char* arr[],int low, int high){
    int i = low - 1;
    for(int j = 0; j <= high; j++){
        if(!(isalpha(*arr[j]) || isdigit(*arr[j]) || isspace(*arr[j]))){
            swap(&arr[++i], &arr[j]);
        }
    }

    return i+1;
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
        *(temp++) = c;
        *(temp) = '\0';
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
    printf("\n#%d\n\n", paragraph);
    for(int i = 0; i < linecount; ++i){
        printf("\t%s", lines[i]);
    }
    printf("\n");
    ++paragraph;
}

int main(int argc, char* argv[]){
    int reverse = 1;
    int numeric = 0;
    int lower_upper_nodiff = 0;
    int directory_order = 0;

    for(int i = 1; i < argc; ++i){
        if(*argv[i] == '-'){
            switch(*(argv[i]+1)){
                case 'r':
                    reverse = -1;
                    continue;
                case 'n':
                    numeric = 1;
                    continue;
                case 'f':
                    lower_upper_nodiff = 1;
                    continue;
                case 'd':
                    directory_order = 1;
                    continue;
                default:
                    printf("Argument #%d %c: Argument unknown\n", i, *(argv[i]+1));
                    continue;
            }
        }else{
            printf("Unknown command\n");
            continue;
        }
    }

    int line_count = 0;
    int (*compare_method[])(char* a, char* b) = {strcmp, numcmp, lowHighNoDiff};
    int choice = 0;
    if(numeric) choice = 1;
    if(lower_upper_nodiff) choice = 2;

    while(line_count = readlines()){
        int low = 0;
        if(directory_order) low = directoryOrder(lines, 0, line_count - 1);
        myqsort(lines, low, line_count - 1, compare_method[choice], reverse);
        writelines(line_count);
        freem(lines[0]);
    }

    printf("End");
}

