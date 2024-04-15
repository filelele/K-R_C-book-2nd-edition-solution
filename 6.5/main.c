/*Write a function undef that will remove a name and definition from the table
maintained by lookup and install.*/

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
        || (to_return -> name = strdup(s)) || (to_return -> replace = strdup(t)) == NULL) 
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







