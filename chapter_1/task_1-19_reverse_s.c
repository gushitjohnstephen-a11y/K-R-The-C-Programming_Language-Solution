/*
 A program to read a set of text lines and print the longest
 */

#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int get_line(char line[], int maxline);
void copy(char to[], char from []);
void reverse(char reverse[], char s[]);

int main(){
    int len;                // current line length
    int max;                // maximum length seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here
    char reversed[MAXLINE]; // the reversed line is stored here

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(longest, line);
            reverse(reversed, longest);
        }
    if (max > 0){
        printf("\nLongest - %s", longest);
        printf("\nReversed -%s", reversed);
        // printf("\nReversed - ");
        // for(int i = MAXLINE -1; i >= 0; --i)
        //     printf("%c", reversed[i]);
    }
    return 0;
}

// get_line: read a line into character array -> "s", return length
int get_line(char s[], int lim){

    int c, i;

    for(i=0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    // end of string indicated by null
    s[i]= '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;

    // Adding a null to the end of copied string
    to[i] = '\0';

}

void reverse(char reverse[], char s[]){
    // find new line
    // word backwords from there
    int null_idx = 0;   //position of null
    int offset = 1;     //position of character

    // find null index
    while(s[null_idx] != '\0'){
        ++null_idx;
    }

    for(int i = 0; null_idx > i; ++i){
        // if(s[MAXLINE - 1 -i] != '\0')
        reverse[i] = s[null_idx - offset];
        ++offset;
    }
}
