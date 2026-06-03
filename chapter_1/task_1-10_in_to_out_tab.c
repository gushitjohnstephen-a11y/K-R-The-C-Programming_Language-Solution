#include <stdio.h>

int main(){
    // \t -> 11(octal)
    // \b -> 10(octal)
    // \\ -> 134(octal)

    int c, ch_type;
    while ((c = getchar()) != EOF){
        if ((c != '\t') && (c != '\b') && (c != '\\')){
                // putchar(' ');
                putchar(c);
        }
        else{
            if (c == '\t'){
                putchar('\\');
                putchar('t');
            }
            if (c == '\b'){
                putchar('\\');
                putchar('b');
            }
            if (c == '\\'){
                putchar('\\');
                putchar('\\');
            }
        }
    }
}
