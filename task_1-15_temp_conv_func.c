#include <stdio.h>

// prototype
float temp_conv(float temp_in_fahr_or_cels, char config);

int main(){
    printf("50 deg cels to fahr is - %.1f", temp_conv(50, 'c'));
    printf("\n50 deg fahr to cels is - %.1f", temp_conv(50, 'f'));

    return 0;
}

float temp_conv(float temp, char config){
    float conv_temp = 0;
    if (config == 'f')
        // celsius formula
        conv_temp = (5 * (temp - 32))/9;
    else if (config == 'c')
        // fahr formula
        conv_temp = (9 * temp)/5 + 32;
    else
        printf("Wrong config, use f(fahr) or c(cels)");

    return conv_temp;
}
