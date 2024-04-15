//verify that the expression getchar() != EOF equal to 0 or 1
#include<stdio.h>

int main () {
    int c;
    while((c = (getchar() != EOF)) != 0){
        printf("%d\n",c);
    }
    printf("%d\n",c);
}