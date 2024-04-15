/*Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given        0123 45678 9 10
preference?*/

#include<stdio.h>
#define TAB 4
#define MAXLINE 1000
#define INSPACE 1
#define OUTSPACE 0


int entabByLine(char s[MAXLINE]) {
    int c;
    int i = 0;
    int space_count = 0;
    int state = OUTSPACE;
    while((c = getchar()) != EOF && c != '\n' && i < MAXLINE){
        if(c == ' '){
            state = INSPACE;
            ++space_count;
            continue;

        } else if(state = INSPACE) {
            state = OUTSPACE;
            int tab_need = space_count/TAB;
            int space_need = space_count%TAB;
            for(int t = 0; t < tab_need; ++t){
                s[i] = 't';//replace a tab with character 't' to visualize things better
                ++i;
            }
            for(int t = 0; t < space_need; ++t){
                s[i] = 'c';//better visualize
                ++i;
            }
            space_count = 0;
        }
        s[i] = c;
        ++i;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    return i;
}

int main(){
    int len;
    char line[MAXLINE];
    while((len = entabByLine(line)) > 0) {
        for(int i = 0; i<len ; ++i){
            printf("%c", line[i]);
        }
        printf("\n");
    }
}