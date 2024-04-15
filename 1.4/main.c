#include <stdio.h>

float celToFahr(float cel) {
    float fahr;
    fahr = cel * 9.0/5.0 + 32;
    return fahr;
}
int main () {
    float celToFahr(float cel) {
        float fahr;
        fahr = cel * 9.0/5.0 + 32;
        return fahr;
    }
    
    float cel;
    float upper = 200;
    float lower = 0;
    int step = 10;
    cel = lower;
    printf("Celsius | Fahrenheit\n");
    while (cel != upper) {
        printf("%7.0f | %10.1f\n", cel, celToFahr(cel));
        cel += step;
    }
}