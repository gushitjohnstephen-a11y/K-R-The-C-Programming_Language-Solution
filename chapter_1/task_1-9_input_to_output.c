#include <stdio.h>

int main(){
    int c, out_c;
    int blank;

    blank = 0;

    // goal is to get the program to ignore any blank space, provided another
    // blank space preceeds it.

    // keyboard listening lifetime
    while((c = getchar()) != EOF){
        if(c == ' '){
            blank ++;
            if(blank < 2){
                out_c = putchar(c);}
            // else{
            //     out_c = putchar('\b');
            // }
        }
        else{
            blank = 0;
            // blank --; blank can be negative
            out_c = putchar(c);
        }

    }

    printf("\n%d\n", out_c); // copied output
}

// INPUT TO OUTPUT ALTERNATIVE
// int main(){
//     int c, out_c, blank_count;
//     blank_count = 0;

//     while ((c = getchar()) != EOF){
//         if (c == ' ')
//             ++blank_count;
//         else
//             blank_count = 0;

//         if (blank_count <= 1)
//             out_c = putchar(c);

// }
//     printf("\n %d", out_c);
// }
