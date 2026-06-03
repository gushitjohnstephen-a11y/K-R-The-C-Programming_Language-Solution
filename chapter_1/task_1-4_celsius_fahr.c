#include <stdio.h>

int main(){
    printf("`C TO `F\n");

    float celsius, fahr;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper){
        fahr = (9 * celsius)/5 + 32;
        printf("%3.0f %6.1f\n", celsius, fahr); //note %f refers to double
        celsius += step;
    }
}
