/*Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/

#include<stdio.h>
#define MAXLINE 1000
#define MAXCOL 50
#define TAB 4
//get line only function
int getline(char s[MAXLINE]){
    int i;
    int c;
    for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; //Null-terminate string
    return i;
}

//print line, break it down when too long
void printLine(char s[MAXLINE]) {
    int count_col = 0;
    int i = 0;
    int char_in_word = 0;
    char word[25];
    int w = 0;
    while(s[i] != '\0'){
        
        //when encounter non_blank string, treat it as a word
        if(s[i] != ' ' && s[i] != '\t'){
            while(s[i] != ' ' && s[i] != '\t'){//loop through all non_blank chars until a blank
                word[w] = s[i];                // store all non_blank chars in a word array
                ++w;
                ++i;
                ++char_in_word;
            }
            word[w] = '\0';                     
            count_col += char_in_word;//add the word length to column counter
            if(count_col > MAXCOL) {  //If column counter exceed maxcol
                count_col = char_in_word;//put the word in a newline, set counter to word length
                putchar('\n');           // in that new line   
                printf("%s", word);
            } else printf("%s", word);//if not exceed maxcol then just print it,counter was set right
            w = 0;
            char_in_word = 0;
        }
        
        //Handle outside of a word(non_blank string), either a space or a tab
        if(s[i] == ' '){
            ++count_col;
            if(count_col > MAXCOL){
                printf("\n");
                count_col = 0;
            }else putchar(s[i]);
            ++i;
        }

        if(s[i] == '\t'){
            count_col += TAB;
            if(count_col > MAXCOL){
                printf("\n");
                count_col = 0;
            } else printf("%c", s[i]);
            ++i;
        }
    }
}

int main() {
    int len;
    char input[MAXLINE];
    while((len = getline(input)) > 0) {
        printLine(input);
    }
}
