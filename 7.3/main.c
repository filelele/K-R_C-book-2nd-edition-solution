/*Revise minprintf to handle more of the other facilities of printf.*/
#include<stdio.h>
#include<stdarg.h>
void minprintf(char* fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    char* traverser = fmt;
    for(;*traverser != '\0'; traverser++){
        if(*traverser == '%'){
            switch(*++traverser){
                case 'd':
                    printf("%d", va_arg(ap, int));
                    break;
                case 'f':
                case 'lf':
                case 'e':
                case 'g':
                    printf("%g", va_arg(ap, double));
                    break;
                case 's':
                    printf("%s", va_arg(ap, char*));
                    break;
                case 'o':
                    printf("%o", va_arg(ap, int));
                    break;
                default:
                    putchar(*(traverser-1));
                    putchar(*traverser);
                    break;
            }
        }else putchar(*traverser);
    }

    va_end(ap);
}

int main(){
    minprintf("%s %d %e", "Just a string", 35, 35e10);
}