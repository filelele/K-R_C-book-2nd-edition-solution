/*Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.*/

#include <stdio.h>
#include <stdlib.h> //For isdigit()
#include <limits.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100

double var[100] = {0};
double to_print = 0;

// get the operand/operator into the array, then return a number to indicate its type
int getop(char s[MAXOP])
{
    static int temp = ' '; // Initialize temp

    // Discard any leading spaces
    while (temp == ' ' || temp == '\t' || temp == '\n')
    {
        temp = getchar();
    }

    s[0] = temp;
    temp = ' ';
    // if it is an operator
    int i = 0;
    if ((!isdigit(s[0])) && s[0] != '.')
    {
        if (s[0] == '-')
        {
            if (isdigit(s[++i] = getchar()))
                ;
            else
                return '-';
        }
        else if (s[i] == 's')
        {
            if ((s[++i] = getchar()) == 'i' && (s[++i] = getchar()) == 'n')
                return 1;
            else
                return 's';
        }
        else if (s[i] == 'e')
        {
            if ((s[++i] = getchar()) == 'x' && (s[++i] = getchar()) == 'p')
                return 2;
            else
                return 'e';
        }
        else return s[0];
    }
    // if it is a number
    while (isdigit(s[++i] = getchar()) || s[i] == '.')
    {
        ;
    }
    temp = s[i];
    printf("temp static is now %c\n", temp);
    s[i] = '\0';
    printf("will return a number which is %s\n", s);
    return NUMBER;
}

double val[MAXVAL] = {0};
int valp = 0;
double pop()
{
    if (valp > 0)
        return val[--valp];
    else
        return 0.0;
}

void push(double a)
{
    if (valp >= MAXVAL)
    {
        printf("too long, flush the value array first\n");
    }
    else
        val[valp++] = a;
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
}

void flushStdin()
{
    int c;
    while ((c = getchar()) != EOF)
        ; // Consume and discard characters until newline or end of file
}

int main()
{
    char s[MAXOP];
    int type = 0;
    double op2 = 0;
    int var_index = 0;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            printf("just push %lf to index '%d'\n", val[valp - 1], valp - 1);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            double op1 = pop();
            push(op1 - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            double b = pop();
            double c = pop();
            if (!b)
            {
                printf("Zero division\n");
            }
            else
                push(c / b);
            break;
        case '%':
            int d = (int)pop();
            int e = (int)pop();
            if (!d)
            {
                printf("Zero division\n");
            }
            else
                push(e % d);
            break;
        case 'D':
            duplicateTop();
            printf("Top is duplicated\n");
            break;
        case 'R':
            clearStack();
            printf("Stack position is set to 0\n");
            break;
        case 'S':
            swapTopTwo();
            printf("Top two elements are swaped\n");
            break;
        case 'P':
            topPeek();
            break;
        case 1:
            push(sin(pop()));
            break;
        case 2:
            push(exp(pop()));
            break;
        case '^':
            double g = pop();
            double h = pop();
            push(pow(h, g));
            break;
        case '=':
            int temp;
            while ((temp = getchar()) != EOF && temp != '\n')
                ;
            printf("Variable name(a to z only): ");
            char sl = getchar();
            while ((temp = getchar()) != EOF && temp != '\n')
                ;
            if (sl <= 'z' && sl >= 'a')
                var[sl - 'a'] = pop();
            to_print = var[sl - 'a'];
            printf("\nVariable %c is now: %lf\n", sl, to_print);
            break;
        default:
            if (islower(type))
            {
                push(var[type - 'a']);
            }
            else
            {
                printf("invalid input\n");
            }
            break;
        }
    }
    printf("%.3lf", val[0]);
}