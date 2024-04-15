/*Write a recursive version of the function reverse(s), which reverses the
string s in place.*/
#include<stdio.h>
void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char s[], int left, int right){
    if(left+1<right){
        reverse(s, left+1, right-1);
    }
    swap(&s[left],&s[right]);
}

int main(){
    char test[] = "abcd";
    reverse(test, 0, 3);
    printf("%s", test);
}