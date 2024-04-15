/*An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.*/

#include <stdio.h>
#include <stdlib.h> //For atof()
#include <limits.h>
#include <ctype.h> //for isdigit()
#include <math.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100
#define MAXLINE 1000

double var[100] = {0};
double to_print = 0;

int getline(char s[])
{
    int c, i;

    for (i = 0; i < MAXVAL - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

double val[MAXVAL] = {0};
int valp = 0;
double pop()
{
    if (valp > 0)
    {
        if (valp == 1)
        {
            double res = val[--valp];
            val[0] = 0;
            return res;
        }
        return val[--valp];
    }
    else
        return 0;
}

void push(double ab)
{
    if (valp >= MAXVAL)
    {
        printf("too long, flush the value array first\n");
    }
    else
        val[valp++] = ab;
}

// print out top of stack
void topPeek()
{
    to_print = val[0];
    printf("The top element is %.3f\n", to_print);
}

// duplicate top
void duplicateTop()
{
    push(val[0]);
}

void swapTopTwo()
{
    double t = val[0];
    if (val[1] != 0)
    {
        val[0] = val[1];
        val[1] = t;
    }
    else
    {
        printf("second position is now 0, is that what you intended to do, or just it is initialized that way\n");
        val[0] = val[1];
        val[1] = t;
        if (valp == 1)
            ++valp;
    }
}

void clearStack()
{
    valp = 0;
    val[0] = 0;
}

int main()
{
    char s[MAXLINE];
    int count = 0;
    while (getline(s) > 0)
    {
        clearStack();
        int i = 0;
        while (s[i] != '\n')
        {
            while (s[i] == ' ' || s[i] == '\t')
                ++i;
            if (isdigit(s[i]))
            {
                char num[70];
                int a = 0;
                printf("Reading number. . .\n");
                while (isdigit(num[a] = s[i]) || s[i] == '.')
                {
                    ++a;
                    ++i;
                }
                num[a] = '\0';
                push(atof(num));
                printf("Pushed: %s\n", num);
            }
            else
            {
                double op2;
                switch (s[i])
                {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '\\':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                case '%':
                    op2 = pop();
                    push((int)pop() % (int)op2);
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case 's':
                    if (s[i + 1] == 'i' && s[i + 2] == 'n')
                    {
                        i += 2;
                        push(sin(pop()));
                        break;
                    }
                    else if (s[i + 1] == 't' && s[i + 2] == 'o')
                    {
                        i += 3;
                        // only a-z variable name
                        if (s[i] > 'z' || s[i] < 'a')
                        {
                            ++i;
                            continue;
                        }
                        var[s[i] - 'a'] = pop();
                        printf("Stored %.3f in variable '%c'\n", var[s[i] - 'a'], s[i]);
                        break;
                    }
                    else
                        ;
                default:
                    if (islower(s[i]))
                    {
                        int index = s[i] - 'a';
                        printf("Variable '%c' index: %d\n", s[i], index); // Debugging output: Print the calculated index
                        double variableValue = var[index];
                        printf("Variable '%c' value: %.3f\n", s[i], variableValue); // Debugging output: Print the variable value
                        push(variableValue);
                        printf("Pushed variable '%c' value: %.3f\n", s[i], variableValue); // Debugging output: Print the variable value pushed to the stack
                        break;
                    }
                    else
                    {
                        printf("Unhandled character: %c\n", s[i]);
                        printf("invalid input\n");
                    }
                    break;
                }
                ++i;
            }
        }
        printf("Line %d result: %.2lf\n", ++count, val[0]);
    }
}