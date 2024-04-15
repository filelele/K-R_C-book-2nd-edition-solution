/*Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/

#include<stdio.h>
#define MAX 1000

void expand(char s1[MAX], char s2[MAX]){
    int i,j = 0;
    int state = 0;
    for(i = 0; s1[i] != '\0';){
        //handling exception of trailing '-' of input
        if(i == 0 || s1[i+1] == 'EOF'){
            if(s1[i] == '-'){
                s2[j++] = s1[i++];
                continue;
            }
        }
        
        if(s1[i] == '-' && (s1[i-1] < s1[i+1]) &&
           (s1[i-1]<='z' && s1[i-1]>='a' && s1[i+1]<='z' && s1[i+1]>='a') ||
           (s1[i-1]<='9' && s1[i-1]>='0' && s1[i+1]<='9' && s1[i+1]>='0')){
            state = 1;
        }

        //i is at '-', use that
        if(state == 0) s2[j++] = s1[i++];
        
        if(state == 1){
            for(;s2[j-1] < s1[i+1] - 1/*expand to s2 all but the upperbound*/; ++j){    
                s2[j] = s2[j-1]+1;
            }//loop end, j is after the expanded shorthand
            i++;// i skip '-' and the upperbound of the shorthand
            state = 0;
        }
    }
    s2[j] = '\0';
}

int main(){
    char s1[MAX] = "a-z0-9-";

    char s4[MAX] = "0-2-11 -a-z";

    char t[MAX];
    expand(s1,t);
    printf("%s\n%s\n\n", s1, t);
    fflush(stdout);
    expand(s4,t);
    printf("%s\n%s\n\n", s4, t);
    fflush(stdout);
}
