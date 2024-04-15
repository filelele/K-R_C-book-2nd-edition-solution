#include <stdio.h>

float celToFahr (int cel) {
    return cel*9.0/5.0 + 32;
}

int main () {
    printf("Celsius to Fahraheit using For Loop\n");
    for(int cel = 250; cel >= 0; cel -= 10) {
        printf("%6d %5.1f\n", cel, celToFahr(cel));
    }
}