#include <stdio.h>

#define IN 1
#define OUT 0

// We'll assume no word input will have more than
// 10 characters

int main(){
    int c, state, word_len;
    int hist_arr[10]; // creating 10 element array

    // initializing all elements of array to zero
    for (int i = 0; i < 10; ++i)
        hist_arr[i] = 0;


    // state = OUT;
    word_len = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            // state = OUT;

            // -1 because no word length will come as zero,
            // effectively leaving the first element unchanged
            ++hist_arr[word_len-1];
            // printf("\nbefore reset-%d", word_len);
            word_len = 0;
            // printf("\nafter reset-%d", word_len);

        }
        else{
            // state = IN;
            ++word_len;
        }
    }
    ++hist_arr[word_len-1];
    // printf("\nbefore reset-%d", word_len);
    // printf("\nafter reset-%d", word_len);

    for (int i = 1; i < 11; ++i){
        printf("\n%d character(s) - ", i);
        for (int j = hist_arr[i-1]; j > 0; --j)
            printf("*");
    }
}
