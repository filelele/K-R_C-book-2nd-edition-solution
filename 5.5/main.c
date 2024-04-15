/*Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s.*/

#include <stdio.h>
#include <string.h>
#define MAX 1000
char allocbuf[MAX];
char *allocp = allocbuf;

char *alloc(int n)
{
    if ((allocbuf + MAX) - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        printf("Buffer overflow\n");
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + MAX)
        allocp = p;
}

char *mstrncpy(char *s, char *t, int n)
{
    if (n > strlen(t))
    {
        return "WTF";
    }

    char *a = alloc(strlen(s));
    char *start = a;
    while (*(a++) = *(s++))
        ;
    a = start;

    for (int i = 0; i < n && *a != '\0'; ++i)
    {
        *(a++) = *(t++);
    }

    return start;
}

char* mstrncat(char* s, char* t, int n){
    if(n > strlen(t)) return "WTF";
    
    char* a = alloc(strlen(s) + n + 1);
    char* to_return = a;
    while(*(a++) = *(s++)) ;
    --a;

    for(int i = 0; i < n; ++i){
        *(a++) = *(t++);
    }

    return to_return;
}

int mstrncmp(char* s, char* t, int n){
    if(n == 0) return -2;
    
    int i = 0;
    while((i++) < n && *(s++) == *(t++)) ;
    --s;
    --t;
    if(*s == *t) return 0;
    else{
        return *s > *t ? 1 : -1;
    }
}

int main()
{
    //mstrncpy
    char *test1 = "abcd123";
    char *result1 = mstrncpy(test1, "rtl", 3);
    printf("%s\n", result1);

    //mstrncat
    char* test2 = "abc";
    char* result2 = mstrncat(test2, "defghiklmn", 4.6);
    printf("%s\n", result2); 

    //mstrncmp
    printf("%d\n", mstrncmp("abcde123", "abcee1233", 3));
    printf("%d\n", mstrncmp("abcde123", "abcee1233", 5));
    afree(result1);
}