/*Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent*/

#include<stdio.h>
#include<ctype.h>

int atoi(char s[]){//string to int, serve the exponential part of atof later
    int num = 0;
    int i = 0;
    
    for(;s[i] != '\0' && s[i] == ' ';++i)
        ;
    
    int sign = 1;
    if(s[i] == '+' || s[i] == '-'){
        if(s[i] == '-') sign = -1;
        ++i;
    }

    for(; s[i] != '\0'; ++i){
        num = num*10 + (s[i] - '0');
    }
    return num*sign;
}

double atof(char s[]){
    int i = 0;  //main loop variable of s
    for(;s[i] != '\0' && s[i] == ' '; ++i){
        ;
    }//remove heading space

    int sign = 1;
    if(s[i] == '+' || s[i] == '-'){
        if(s[i] == '-') sign = -1;
        ++i;
    }//get the sign

    double num = 0;// return this
    for(;s[i] != '\0' && isdigit(s[i]); ++i){
        num = num*10 + (s[i] - '0');
    }//get value until a '.'

    double power = 1;
    if(s[i] == '.'){
        ++i;
    }//handle '.'

    for(;s[i]!= '\0' && isdigit(s[i]);++i){
        power *= 10;
        num = num*10 + (s[i] - '0');
    }//continue increasing num, from now on also increase power

    int expi = 0;//exponential as int
    char expc[100];//exponential as string literal
    if(s[i] == 'e' || s[i] == 'E'){
        ++i;
        
        int k;
        for(k = 0; s[i] != '\0'; ++i, ++k){
            expc[k] = s[i];
        }
        expc[k] = '\0';// get the exponential string literal
        expi = atoi(expc);//convert the string to int
    }
    if(expi > 0){//if positive exponential, increase power
        for(int a = 0; a<expi; ++a){
            power*=10;
        }
    }else if(expi < 0){//else . . .
        for(int a = 0; a > expi; --a){
            power/=10;
        }
    }

    return num*power*sign;
}

int main(){
    printf("%f", atof("12e-5"));
}