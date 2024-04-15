/*Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters*/

#include<stdio.h>
#define MAX 1000
void getString(char s[MAX]){
    int c;
    int i = 0;
    while(i < MAX-1 && (c=getchar())!= EOF){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
}

void charToEscape(char s[], char t[]){
    int i,j = 0;
    for(i = 0; s[i] != '\0'; ++i){
        switch(s[i]){
            case '\t': 
                t[j++] = '\\';
                t[j++] = 't'; 
                break;
            case '\n': 
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

void escapeToChar(char s[], char t[]){
    int i,j = 0;
    for(i = 0; s[i] != '\0'; ++i){
        if(s[i] == '\\') {
            ++i;
            switch(s[i]){
                case 't': 
                    t[j++] ='\t';
                    break;
                case 'n': 
                    t[j++] = '\n';
                    break;
                default:
                    t[j++] = s[i-1];
                    t[j++] = s[i];
                    break;
            }
        }else t[j++] = s[i];
    }

    t[j] = '\0';
}

int main(){
    char s[MAX];
    char t[MAX];
    char d[MAX];
    getString(s);
    charToEscape(s,t);
    escapeToChar(t,d);
    printf("\n%s\n", t);
    printf("\n%s\n", d);
}