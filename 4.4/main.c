
/*Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.*/

#include<stdio.h>
#include<stdlib.h> //For isdigit()
#include <limits.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100

int buffer = INT_MIN;

int getch(){
    int res;
    if(buffer != INT_MIN){
        res = buffer;
        buffer = INT_MIN;
    }else res = getchar();
    return res;
}

void ungetch(int c){
    buffer = c;
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
    if(c != '\n' && c != EOF)
    ungetch(c);//to return the operand or anything not in this number back for future getch()
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
    printf("The top element is %.3f\n", val[0]);
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
    int type = 0;
    double op2 = 0;
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
            default:
                printf("invalid input\n");
                break;
        }
    }
    printf("%.3lf", val[0]);
}