#include <stdio.h>

int main(){
    // declaration
    int c, bl, tb, nl;

    // initialization
    bl = 0;
    tb = 0;
    nl = 0;

    // loop to count
    while((c = getchar()) != EOF){
        if(c == '\t'){
            ++ tb;}
        else if(c == ' '){
            ++ bl;}
        else if(c == '\n'){
            ++ nl;}
}
    printf("\nblank - %d\ntab - %d\nnewline - %d\n", bl, tb, nl);
}

//FIXED
// int main(){
//     int c, nt, nb, nl, nc;
//     while ((c = getchar()) != EOF){
//         ++ nc;

//         if (c == '\t')
//             ++nt;
//         if (c == ' ')
//             ++nb;
//         if (c == '\n')
//             ++nl;
//     }
//     if (nc > 0)
//         ++nl;
//     printf("\nno_lines-%d, no_blanks-%d, no_tab-%d",
//         nl, nb, nt);
// }
