/*C keyword counter*/

//keep getting word until eof -> each word save into a temp char*, search for it inside the struct keytab
//, ++ the count at that keytab

/*Our version of getword does not properly handle underscores, string constants,
comments, or preprocessor control lines. Write a better version.*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAXWORD 30

struct keyword {
    char word[MAXWORD];
    int count;
} keystab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "int", 0,
    "double", 0,
    "if", 0,

};

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

int getword(char* w) {
    int c;
    int count = 0;

    while (isspace(c = getch())) ; // Skip whitespace
    //handle string literal
    if(c == '"'){
        while((c = getch()) != '"'){
            if (c == EOF) return EOF;
            if(c == '\\'){
                c = getch();
                continue;
            }
        }
        c = getch();
    }

    if (c == EOF) {
        return EOF;
    }

    if (!isalnum(c)) {
        *w = '\0'; // Handle non-alphanumeric characters
        return 0;
    } else {
        *w++ = c;
        count++;
    }

    while (isalnum(c = getch()) && count < MAXWORD - 1) {
        *w++ = c;
        count++;
    }
    
    *w = '\0';
    if (c != EOF && !isspace(c)) {
        ungetch(c); // Put back the character if not EOF
    }
    return count;
}

#define NKEYS sizeof keystab / sizeof(struct keyword)

int binsearch(struct keyword a[NKEYS], char* word){
    int low = 0;
    int high = NKEYS - 1;

    while(low < high){
        int mid = (low+high)/2;
        if(strcmp(word, a[mid].word) < 0) {
            high = mid - 1;
            continue;
        }
        else if(strcmp(word, a[mid].word) > 0){
            low = mid + 1;
            continue;
        }else return mid;
    }

    return -1;
}

int compareStruct(const void *a, const void *b){
    const struct keyword *ka = (const struct keyword *)a;
    const struct keyword *kb = (const struct keyword *)b;
    return strcmp(ka->word, kb->word);
}
int main(){
    qsort(keystab, NKEYS, sizeof(struct keyword), compareStruct);
    
    char word[MAXWORD];
    int len = 0;
    while((len = getword(word)) != EOF){
        printf("Word length is: %d\n", len);
        if(!len) continue;
        else{
            int pos = binsearch(keystab, word);
            if(pos == -1) continue;
            else keystab[pos].count += 1; 
            printf("insert to position %d\n", pos);
        }
    }
}