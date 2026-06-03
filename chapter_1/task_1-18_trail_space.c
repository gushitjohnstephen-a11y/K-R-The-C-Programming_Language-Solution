#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char str_arr[], int max_len);
void copy(char to[], char from[]);
int count_copy(char to[]);
void clean(char raw_line[]);


int main(){
    int len, max, stored_len;
    char line[MAX_LENGTH], longest[MAX_LENGTH];

    max = 0;

    while((len = get_line(line, MAX_LENGTH)) > 0){
        if (len > max){
            max = len;
            clean(line);
            copy(longest, line);
            stored_len = len;
        }
    }
    printf("\nThis is the longest line - [%s] with %d characters",
        longest, count_copy(longest));
    return 0;
}

int get_line(char str_arr[], int max_len){
    int i, c;
    for(i=0; i< max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        str_arr[i] = c;
    }
    if (c == '\n'){
        str_arr[i] = c;
        ++i;
    }
    str_arr[i] = '\0'; // indicated end of string array
    return i;
}

void copy(char to[], char from[]){
        int i = 0;

        while ((to[i] = from[i]) != '\0'){
            ++i;
        }
}

void clean(char raw_line[]){
    // works by shifting the position of the null and newline characters
    //
    int k = 0;
    for(int i = 0; i < MAX_LENGTH - 1 ;++i){
        if(raw_line[i] == '\n'){
            // trailing blanks & tabs
            if(raw_line[i -1] == ' ' || raw_line[i -1] == '\t'){
                // moving untill we find a non-blank character
                while(raw_line[i-1] == ' ' || raw_line[i -1] == '\t'){
                    // raw_line[i] = '\n';
                    raw_line[i] = '\0';
                    --i;
                }
                // make changes after locating the non-blank character
                // raw_line[k] = '\0';
            }
            //empty line
            if(i == 0 && raw_line[i] == '\n')
                // since copy only works provided '\0' isn't in arr
                raw_line[i] = '\0';
        }
    }
}

int count_copy(char to[]){
    int len = 0;
    for(int i = 0; to[i] != '\0'; ++i){
        ++len;
    }
    return len;
}
