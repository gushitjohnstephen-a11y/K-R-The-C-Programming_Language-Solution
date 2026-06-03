#include <stdio.h>

// int main(){
//     int c;
//     while((c = getchar())!= EOF){
//         printf("\t--%d", (c == EOF));}
// }

int main(){
    int c;
    int result;
    while((result = (c = getchar())) != EOF)
        printf("%d\n", result);
    printf("%d\n", result); // prints 0 when EOF is hit
}
