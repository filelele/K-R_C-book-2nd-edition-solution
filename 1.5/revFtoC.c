#include <stdio.h>

float fahrToCel (int fahr) {
    return 5.0/9.0*(fahr-32);
}

int main () {
    int upper = 250;
    int lower = 0;
    int fahr = upper;
    int step = 10;
    printf("Fahr to Cel in reverse order using While loop\n");
    while (fahr >= 0) {
        printf ("%6d %5.1f\n", fahr, fahrToCel(fahr));
        fahr -= 10;
    }
}