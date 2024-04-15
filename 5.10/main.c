/*Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAXVAL 100
double valuebuf[MAXVAL];
int vali = 0;
void push(double a){
    if(vali >= MAXVAL) printf("Buffer overflow\n");
    else {
        valuebuf[vali] = a;
        vali++;
    }
}

double pop(){
    return vali > 0 ? valuebuf[--vali] : 0;
}

int main(int argc, char* argv[]){
    /*argv[1] = "2";
    argv[2] = "3";
    argv[3] = "5";
    argv[4] = "+";
    argv[5] = "*";
    argc = 6;*/
    ++argv;
    for(int i = 1; i < argc; ++i, ++argv){
        double op2;
        int c;
        if(isdigit(**argv) || ((**argv == '+' || **argv == '-') && strlen(*argv) > 1)){
            push(atof(*argv));
            continue;
        }

        if(strlen(*argv) == 1){
            switch(**argv){
                case '+':
                    push(pop()+pop());
                    continue;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    continue;
                case 'x':
                    push(pop()*pop());
                    continue;
                case '/':
                    op2 = pop();
                    push(pop()/op2);
                    continue;
                default:
                    printf("invalid input\n");
                    break;
            }
        }
    }
    for(int i = 0; i < vali; ++i){
        printf("\n%lf ", valuebuf[i]);
    }
}