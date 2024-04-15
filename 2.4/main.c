/*Write an alternative version of squeeze(remove_from,to_remove) that deletes each character in
remove_from that matches any character in the string to_remove.*/

#include<stdio.h>
#define MAX 1000
#define DETECTED 1
#define NOT_DETECTED 0
void squeeze(char remove_from[MAX], char to_remove[MAX]){
    int i,j;
    int k = 0;
    int state = NOT_DETECTED;
    for(i = 0; remove_from[i] != '\0'; ++i){
        for(j = 0; to_remove[j] != '\0'; ++j){
            if(remove_from[i] == to_remove[j]) state = DETECTED;  
        }

        if(state != DETECTED){
            remove_from[k++] = remove_from[i];
        }else state = NOT_DETECTED;
    }
    remove_from[k] = '\0';
}

int main(){
    char s1[MAX] = "con cac con alo";
    char s2[MAX] = "abcd";
    squeeze(s1, s2);
    printf("%s", s1);
}