/*Write a program that reads a C program and prints in alphabetical order each
group of variable names that are identical in the first 6 characters, but different somewhere
thereafter. Don't count words within strings and comments. Make 6 a parameter that can be
set from the command line*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 30
#define BUFSIZE 100

int getbuf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? getbuf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        getbuf[bufp++] = c;
    else
        printf("Error: buffer full\n");
}

int getword(char *word)
{
	int c;
	char *w = word;
    int lim = MAXWORD;
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c) || c == '_' || c == '#') {
		for ( ; --lim > 0; ++w)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
	} else if (c == '\'') /* skip character constants */
		while ((c = getch()) != '\'')
			;
	else if (c == '\"')  { /* skip string constants */
		while ((c = getch()) != '\"')
			if (c == '\\')
				getch();
	} else if (c == '/' && (c = getch()) == '*') /* skip comments */
		while ((c = getch()) != EOF)
			if (c == '*' && (c = getch()) == '/')
				break;
	*w ='\0';
	return c;
}

char *vartype[] = {
    "int",
    "float",
    "double",
    "char",
    "int*",
    "float*",
    "double*",
    "char*",
    "void*",
};

static void swapString(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char* arr[], int low, int high){
    int i = low - 1;
    char* s = arr[high];
    for(int j = low; j < high; j++){
        if(strcmp(arr[j], s) <= 0) swapString(&arr[j], &arr[++i]);
    }
    swapString(&arr[i+1], &s);
    return i+1;
}

void stringQsort(char* arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        stringQsort(arr, low, pivot - 1);
        stringQsort(arr, pivot+1, high);
    }
}

#define NUM_OF_VARTYPE 9
int binsearch(char* a[], char* word){
    int low = 0;
    int high = NUM_OF_VARTYPE - 1;

    while(low < high){
        int mid = (low+high)/2;
        if(strcmp(word, a[mid]) < 0) {
            high = mid;
            continue;
        }
        else if(strcmp(word, a[mid]) > 0){
            low = mid + 1;
            continue;
        }else return mid;
    }

    return -1;
}

#define NUM_OF_VARTYPE 9

// Binary tree node structure
struct group {
    char* mutual_part;
    char* vars[100];
    int var_count;
    struct group* less;
    struct group* more;
};

void add_to_group(struct group* p, char* word){
    if(p->var_count < 100) p->vars[p->var_count++] = strdup(word);
    else printf("Group full\n");
}

char* mystrndup(const char* s, size_t n) {
    char* p;

    p = (char*)malloc(n + 1);
    if (p != NULL) {
        strncpy(p, s, n);
        p[n] = '\0';
    }
    return p;
}

void addtree(struct group **p, char *word, int n) {
    if (*p != NULL) {
        int cmp = strncmp(word, (*p)->mutual_part, strlen((*p)->mutual_part));
        if (cmp == 0) add_to_group(*p, word);
        else if (cmp < 0) addtree(&((*p)->less), word, n);
        else addtree(&((*p)->more), word, n);
    } else {
        *p = (struct group *)malloc(sizeof(struct group));
        if (*p == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        (*p)->var_count = 0;
        (*p)->mutual_part = mystrndup(word, n);
        (*p)->vars[(*p)->var_count++] = strdup(word);
        (*p)->less = NULL;
        (*p)->more = NULL;
    }
}

// Function to traverse the tree in order and print the groups
void treeprint(const struct group* p) {
    if (p != NULL) {
        treeprint(p->less);
        printf("Group: %s\n", p->mutual_part);
        for (int i = 0; i < p->var_count; i++) {
            printf(" %s\n", p->vars[i]);
        }
        treeprint(p->more);
    }
}

int main(int argc, char *argv[]) {
    int n = 6; // Default value for n
    if (argc == 2) {
        n = atoi(argv[1]); // Read n from command line argument
    }

    int len;
    char word[MAXWORD];
    struct group *root = NULL;
    stringQsort(vartype, 0, NUM_OF_VARTYPE - 1);
    while (getword(word) != EOF) {
        if (binsearch(vartype, word) != -1) {
            len = getword(word);
            addtree(&root, word, n);
        }
    }

    printf("Groups of variable names:\n");
    treeprint(root);

    return 0;
}
