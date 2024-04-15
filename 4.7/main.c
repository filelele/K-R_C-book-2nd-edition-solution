/*Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?*/

#include<stdio.h>
#include<stdlib.h> //For isdigit()
#include <limits.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100

double var[100] = {0};
double to_print = 0;

int buffer[100] = {0};
int buffer_pointer = 0;
int getch(){
    return (buffer_pointer > 0)? buffer[--buffer_pointer] : getchar();
}

void ungetch(int c){
    buffer[buffer_pointer++] = c;
}

void ungets(char s[], int len){
    int i;
    for(i = len - 1; i >= 0 && buffer_pointer < 100; --i){
        ungetch(s[i]);
    }
}

//get the operand/operator into the array, then return a number to indicate its type
int getop(char s[MAXOP]){
    int c;
    //dealing with starting blanks
    while((c = getch()) == ' '|| c == '\t' || c == '\n'){
        ;
    }
    //if it is an operator
    int i = 0;
    s[i] = c;
    if((!isdigit(c)) && c != '.'){
        if(c == '-'){
            if(isdigit(s[++i] = c = getch()))
            ;
            else return '-';
        }else if(c == 's'){
            if((s[++i] = c = getch()) == 'i' && (s[++i] = c = getch()) == 'n' )
            return 1;
            else return 's';
        }else if(c == 'e'){
            if((s[++i] = c = getch()) == 'x' && (s[++i] = c = getch()) == 'p' )
            return 2;
            else return 'e';
        }else return c;
    }
    //if it is a number
    while(isdigit(s[++i] = c = getch())){
        ;
    }

    //if it has fractional part
    if(c == '.'){
        while(isdigit(s[++i] = c = getch())){
            ;
        }//the last character does not belong to this number
    }
    /*if(c != '\n' && c != EOF)
    ungetch(c);to return the operand or anything not in this number back for future getch()
    */
    s[i] = '\0';
    return NUMBER;
}

double val[MAXVAL] = {0};
int valp = 0;
double pop(){
    if(valp>0) return val[--valp];
    else return 0.0;
}

void push(double a){
    if(valp >= MAXVAL){
        printf("too long, flush the value array first\n");
    }else val[valp++] = a;
}

//print out top of stack
void topPeek(){
    to_print = val[0];
    printf("The top element is %.3f\n", to_print);
}

//duplicate top
void duplicateTop(){
    push(val[0]);
}

void swapTopTwo(){
    double t = val[0];
    if(val[1] != 0){
        val[0] = val[1];
        val[1] = t;
    }else{
        printf("second position is now 0, is that what you intended to do, or just it is initialized that way\n");
        val[0] = val[1];
        val[1] = t;
        if(valp == 1) ++valp;
    }
}

void clearStack(){
    valp = 0;
}

int main(){
    char s[MAXOP];
    char ts[] = "5 2 + 3 2 % 5 + +";
    ungets(ts, 17);
    int type = 0;
    double op2 = 0;
    int var_index = 0;
    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
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
                push(pop()*pop());
                break;
            case '/':
                double b = pop();
                double c = pop();
                if(!b){
                    printf("Zero division\n");
                }else push(c/b);
                break;
            case '%':
                int d = (int)pop();
                int e = (int)pop();
                if(!d){
                    printf("Zero division\n");
                }else push(e%d);
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
                while((temp = getchar()) != EOF && temp != '\n')
                ;
                printf("Variable name(a to z only): ");
                char sl = getchar();
                while((temp = getchar()) != EOF && temp != '\n')
                ;
                if(sl <= 'z' && sl >= 'a') var[sl - 'a'] = pop();
                to_print = var[sl-'a'];
                printf("\nVariable %c is now: %lf\n", sl, to_print);
                break;
            default:
                if(type <= 'z' && type >= 'a')
                push(var[type-'a']);
                else printf("invalid input\n");
                break;
        }
    }
    to_print = val[0];
    printf("%.3lf", to_print);
}