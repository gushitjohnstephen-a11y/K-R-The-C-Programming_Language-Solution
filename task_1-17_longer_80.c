#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char str_arr[], int max_length);
void copy(char to[], char from[]);
void paste_multi(char over_80_line[], char clipboard[], int position, int runs);

int main(){
    int len, line_count;
    char str_arr[MAX_LENGTH], over_80[MAX_LENGTH], clipboard[MAX_LENGTH];

    int runs, last_pos;
    runs = last_pos = 0;

    while ((len = get_line(str_arr, MAX_LENGTH)) > 0){
        if (len > 80){
            line_count = len;
            copy(over_80, str_arr);
            // printf("\nThis line is over 80 characters - %s", over_80);
            paste_multi(over_80, clipboard, last_pos, runs);
            last_pos += len;
            ++runs;
        }
    }
    clipboard[last_pos] = '\0';
    printf("\n%s[%d]", clipboard, line_count);
}


int get_line(char str_arr[], int max_length){
    // we want to keep populating out string buffer as long as the length
    // - doesn't exceed our max length,
    // - we don't receive EOF as input,
    // - we don't receive the newline character as input
    int c, i;

    for(i=0; i < max_length - 1 && (c = getchar()) != EOF && c!='\n';++i){
        str_arr[i] = c;
    }
    if (c == '\n'){
        str_arr[i] = c;
        ++i;
    }

    // end of string indicated by null
    str_arr[i] = '\0';

    return i;
}

void copy(char to[], char from[]){
    int i = 0;

    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}

void paste_multi(char over_80_line[], char clipboard[], int position, int runs){
    int i_80 = 0;
    if (runs < 1){
        for(int i = 0; over_80_line[i] != '\0'; ++i)
            clipboard[i] = over_80_line[i];
    }
    else{
        for(int i = position; over_80_line[i_80] != '\0'; ++i){
            clipboard[i] = over_80_line[i_80];
            ++i_80;
        }
    }
}
