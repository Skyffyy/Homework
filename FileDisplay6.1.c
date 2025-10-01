#include <stdio.h>
#include "mystring.h"
#include "mynumber.h"

void filestat(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) { 
        printf("Cannot open file: %s\n", filename); 
        return; 
    }

    fseek(f, 0, 2); 
    long size = ftell(f);
    rewind(f); 
    int lines = 0, words = 0;
    char c, prev = ' ';

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') lines++;
        if (is_whitespace(c) && !is_whitespace(prev)) words++;
        prev = c;
    }
    if (!is_whitespace(prev)) words++; 

    fclose(f);

    printf("Filename: %s\nSize (bytes): %ld\nLines: %d\nWords: %d\n\n",
           filename, size, lines, words);
}

int main(int argc, char *argv[]) {
    if (argc < 2) { 
        printf("Usage: %s <files...>\n", argv[0]); 
        return 1; 
    }

    for (int i = 1; i < argc; i++) {
        filestat(argv[i]);
    }

    return 0;
}
