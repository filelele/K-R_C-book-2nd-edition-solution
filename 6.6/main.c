/*Implement a simple version of the #define processor (i.e., no arguments)
suitable for use with C programs, based on the routines of this section. You may also find
getch and ungetch helpful*/

#include<stdio.h>
#include<string.h>

struct adef {
    char* name;
    char* replace;
    struct adef* next;
};

#define HASHSIZE 100
struct adef* hashtab[HASHSIZE];

#define HASHDISTRIBUTE 31
unsigned int hash(char* s){
    unsigned int to_return = 0;
    while(*s != '\0'){
        to_return += (*s)*HASHDISTRIBUTE;
        ++s;
    }

    return to_return%HASHSIZE;
}

struct adef* lookup(char* s){
    struct adef* to_return;
    for(to_return = hashtab[hash(s)]; to_return != NULL; to_return = to_return->next){
        if(strcmp(s,to_return->name) == 0) return to_return;
    }

    return NULL;
}

struct adef* install(char* s, char* t){
    struct adef* to_return;
    
    if((to_return = lookup(s)) == NULL){
        int hashval = hash(s);
        
        if((to_return = (struct adef*)malloc(sizeof(struct adef))) == NULL 
        || (to_return -> name = strdup(s)) == NULL || (to_return -> replace = strdup(t)) == NULL) 
            return NULL;
        
        to_return -> next = hashtab[hashval];
        hashtab[hashval] = to_return;
    }else{
        free(to_return->replace);
        if((to_return->replace = strdup(t)) == NULL) return NULL;
    }

    return to_return;
}

void freedef(struct adef* p){
    if(p == NULL) return;
    free(p->name);
    free(p->replace);
    free(p);
    p = NULL;
}
void uninstall(char* s){
    struct adef* to_remove;
    unsigned int hashval = hash(s);
    if((to_remove = lookup(s)) == NULL) ;
    else if(to_remove != hashtab[hashval]){
        struct adef* before;
        for(before = hashtab[hashval]; before->next != to_remove; before= before->next){
            ;
        }

        before->next = to_remove->next;
        freedef(to_remove);
    }else{
        hashtab[hashval] = to_remove->next;
        freedef(to_remove);
    }
}


#define MAXLINE 1000
int readline(char* s){
    int c;
    int i = 0;
    while(i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF ){
        *(s++) = c;
        ++i;
    }

    if(c == '\n'){
        ++i;
        *(s++) = '\n';
    }

    *s = '\0';
    return i;
}

#define MAXWORD 30
#define MAXLINES 1000
char* lines[MAXLINES];
int readAllLines(char* lines[], int max){
    int line_count = 0;
    char temp[MAXLINE];
    char* s = temp;
    while(line_count < max && readline(s) > 0){
        if((lines[line_count++] = strdup(s)) == NULL){
            printf("Not enough memory\n");
            break;
        }
    }

    return line_count;
}

void writeLines(char* lines[], int linec){
    printf("\n");
    for(int i = 0; i < linec; ++i){
        printf("%s", lines[i]);
    }
}

int readword(char* line, char* word, char** line_traverse) {
    char* start = *line_traverse;
    char* end;
    int length;

    // Skip any leading whitespace
    while (isspace(*start)) {
        start++;
    }

    // Check if we are at the end of the line
    if (*start == '\0') {
        *word = '\0';  // Null-terminate the word
        return 0;
    }

    // Find the end of the word
    end = start;
    while (!isspace(*end)) {
        ++end;
    }

    // Calculate the word length
    length = end - start;

    // Copy the word into the provided array
    strncpy(word, start, length);
    word[length] = '\0';  // Null-terminate the word

    // Update the line_traverse pointer to point to the next character after the word
    *line_traverse = end;

    return length;
}
int main(){
    int line_count = readAllLines(lines, MAXLINES);

    //add all pair of name-replacement to hashtab
    char word[MAXWORD];
    char name[MAXWORD];
    char replace[MAXWORD];
    for(int i = 0; i < line_count; ++i){
        char* line_traverse = lines[i];
        while(readword(lines[i], word, &line_traverse) > 0){
            if(strcmp(word, "#define") == 0){
                readword(lines[i], name, &line_traverse);
                readword(lines[i], replace, &line_traverse);
                install(name, replace);
            }
        }
    }

    //traverse all lines, find occurence of replacement in each word of each line
    // and replace it, consider replacing whole line if needed
    for(int i = 0; i < line_count; ++i){
        char* line_traverse = lines[i];
        int len;
        struct adef* a;
        char replace_line[MAXLINE*2];
        replace_line[0] = '\0';
        while((len = readword(lines[i], word, &line_traverse)) > 0){
            if(strcmp(word, "#define") == 0){
                strcat(replace_line, " ");
                strcat(replace_line, word);
                readword(lines[i], word, &line_traverse);
                strcat(replace_line, " ");
                strcat(replace_line, word);
                continue;
            }
            
            if((a = lookup(word)) != NULL){
                strcpy(word,a->replace);
            }
            strcat(replace_line, " ");
            strcat(replace_line, word);
        }

        free(lines[i]);
        lines[i] = strdup(replace_line);
        strcat(lines[i], "\n");
    }

    writeLines(lines, line_count);
}