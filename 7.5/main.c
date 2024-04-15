/*Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do
the input and number conversion.*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

#define MAXCAL 1000
long int val[MAXCAL];
long int *valp = val;
long int pop()
{
    if (valp > val)
        return *--valp;
    else
        return 0.0;
}

void push(long int a)
{
    if (valp < (val + MAXCAL))
        *valp++ = a;
    else
        printf("no more space to push\n");
}

#define MAXLINE 1000
int main()
{
    char s[MAXLINE];
    long int c;

    while (scanf("%s", s) != EOF) { // Continue reading until there's input
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) { // Check if the input is a number (including negative numbers)
            c = strtol(s, NULL, 10);
            push(c);
        } else { // Assume it's an operator
            switch (s[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    c = pop();
                    push(pop() - c);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    c = pop();
                    if (c != 0) {
                        push(pop() / c);
                    } else {
                        printf("Division by zero\n");
                        return 1; // Exit the program with an error code
                    }
                    break;
                default:
                    printf("Invalid operator: %c\n", s[0]);
                    return 1; // Exit the program with an error code
            }
        }
    }

    printf("Result: %ld\n", *--valp);
    return 0;
}