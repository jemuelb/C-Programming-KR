#include <stdio.h>

float fahr_to_cel(float a);

main() {

    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    while (fahr <= upper){
        celsius = fahr_to_cel(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahr_to_cel(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}
