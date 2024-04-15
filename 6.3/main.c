/*Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
``and,'' and so on.*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 30

struct word{
    char word[MAXWORD];
    int lines[1000];
    int line_index;
    struct word* left;
    struct word* right;
};

struct word* addtree(struct word* p, char* word, int linenum){
    if(p == NULL){
        p = (struct word*)malloc(sizeof(struct word));
        strcpy(p->word, word);
        p->line_index = 0;
        p->lines[p->line_index++] = linenum;
        p->left = p->right = NULL;
    }else{
        int cmp = strcmp(word, p->word);
        if(cmp < 0) p->left = addtree(p->left, word, linenum);
        else if(cmp > 0) p->right = addtree(p->right, word, linenum);
        else p->lines[p->line_index++] = linenum;
    }

    return p;
}

void treeprint(struct word* p){
    if(p != NULL){
        treeprint(p->left);
        printf("Word: %s\n", p->word);
        printf("Appeared at lines: ");
        for(int i = 0; i < p->line_index; i++){
            printf("%d ", (p->lines)[i]);
        }
        printf("\n\n");
        treeprint(p->right);
    }
}

#define MAXLINE 2000

int readline(char* line){
    int c;
    int i = 0;
    char* s = line;
    
    while(i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF){
        *s++ = c;
        ++i;
    }

    if(c == '\n'){
        *s++ = '\n';
        ++i;
    }

    *s = '\0';
    return i;
}

int getword(char** line_pointer, char* word){
    char* s = *line_pointer;
    while(*s != '\0' && (isspace(*s) ||!isalpha(*s))){
        s++;
    }

    int len = 0;
    char temp[MAXWORD];
    if(isalpha(*s)){
        temp[len++] = *(s++);
    }
    while(isalnum(*s)){
        temp[len++] = *(s++);
    }

    temp[len] = '\0';
    strcpy(word, temp);
    *line_pointer = s;
    return len;
}

char* noise[] = {
    "the",
    "and",
    "about",
    "with",
    "whereas",
    "just",
};

void swap(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char* noise[], int low, int high){
    int i = low - 1;
    char* pivot = noise[high];
    for(int j = low; j < high; j++){
        int cmp = strcmp(noise[j], pivot);
        if(cmp <= 0 ) swap(&noise[++i], &noise[j]);
    }

    swap(&noise[++i], &pivot);
    return i;
}

void noiseSort(char* noise[], int low, int high){
    if(low < high){
        int pivot = partition(noise, low, high);
        noiseSort(noise, low, pivot - 1);
        noiseSort(noise, pivot + 1, high);
    }
}

int binsearch(char* noise[], int low, int high, char* word){
    int mid;
    while(low < high){
        mid = (low+high)/2;
        int cmp = strcmp(word, noise[mid]);
        if(cmp < 0){
            high = mid;
        }else if(cmp > 0){
            low = mid + 1;
        }else return mid;
    }

    return -1;
}

int main(){
    int line_num = 1;
    struct word* root = NULL;
    //sort the noise words array
    noiseSort(noise, 0, 5);
    
    //get line by line until an EOF give a line length zero
    char line[MAXLINE];
    while(readline(line) > 0){
        char word[MAXWORD];
        char* line_pointer = line;
        int word_len = 0;
        while((word_len = getword(&line_pointer, word)) > 0){
            //search for noise word here
            if(binsearch(noise, 0, 5, word) != -1) continue;
            //not noise then add to tree
            root = addtree(root, word, line_num);
        }
        line_num++;
    }

    treeprint(root);
}