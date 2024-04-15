/*Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4).*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define MAXLINE 1000
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

int getline(char *s)
{
    int c;
    int count = 0;
    while ((*s = c = getchar()) != '\n' && *s != EOF)
    {
        ++s;
        ++count;
    }

    if (*s == '\n')
        *(++s) = '\0';

    return *s; // end if return EOF
}

int atoi(char *s)
{
    int num = 0;
    while (isspace(*s))
        s++;

    int sign = 1;
    if (*s == '+' || *s == '-')
    {
        sign = (*s == '+' ? 1 : -1);
        s++;
    }

    while (isdigit(*s))
    {
        num = num * 10 + (*s - '0');
        s++;
    }

    return num * sign;
}

#define MAXNUM 20
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *s)
{
    char *start = s;
    char *end;
    while (*s != '\0')
        s++;
    end = s - 1;

    while (start < end)
    {
        swap(start++, end--);
    }
}

char *itoa(int num)
{
    int sign = 1;
    char *new = alloc(MAXNUM);
    char *to_return = new;
    if (num < 0)
    {
        sign = -1;
        num = -num;
    }

    while (num / 10)
    {
        *(new ++) = num % 10 + '0';
        num /= 10;
    }

    *(new ++) = num % 10 + '0';
    if (sign == -1)
        *(new ++) = '-';
    *new = '\0';

    reverse(to_return);
    return to_return;
}

int strindex(char *s, char *t)
{
    int to_return = -1;

    char *start = s;
    while (*(s++) != *t)
        ;
    --s;
    to_return = s - start;

    while (*s == *t && *t != '\0')
    {
        s++;
        t++;
    }

    if (*t == '\0')
        return to_return;
    else
        return -1;
}
#define MAXBUF 100
int buffer[MAXBUF];
int *bufferp = buffer;

int getch()
{
    return bufferp > buffer ? *(--bufferp) : getchar();
}

void ungetch(int a)
{
    if (bufferp >= buffer + MAXBUF)
        printf("Buffer overflow\n");
    else
        *(bufferp++) = a;
}

#define NUMBER 0
int getop(char *s)
{
    while (isspace(*s = getch()))
        ;

    if (!isdigit(*s) && *s != '-' && *s != '+')
        return *s;

    if (*s == '+' || *s == '-')
    {
        if (isdigit(*(++s) = getch()))
            ++s;
        else
            return *s;
    }

    while (isdigit(*s = getch()))
    {
        ++s;
    }

    if (*s == '.')
    {
        ++s;
        while (isdigit(*s = getch()))
        {
            ++s;
        }
    }

    if (*s != EOF)
        ungetch(*s);
    *s = '\0';
    return NUMBER;
}

int main()
{
    // getline test
    char line[MAXLINE];
    while (getline(line) != EOF)
    {
        printf("%s", line);
    }

    // atoi test
    char *a = "123213.5543";
    printf("\n%d\n", atoi(a));

    // itoa test
    int test = -2134;
    printf("%s\n", itoa(test));

    // strindex test
    char *c1 = "abcdefghik";
    char *c2 = "cd";
    char *c3 = "fghik";
    printf("%d %d", strindex(c1, c2), strindex(c1, c3));
}