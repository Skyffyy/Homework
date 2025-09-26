#include <stdio.h>

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != 0) len++;
    return len;
}

int is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

void filestat(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == 0) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    fseek(fp, 0, 2); 
    long size = ftell(fp);
    rewind(fp);       

    int lines = 0;
    int words = 0;
    char c;
    char prev = ' ';

    while ((c = fgetc(fp)) != -1) {
        if (c == '\n') {
            lines++;
        }
        if (is_whitespace(c)) {
            if (!is_whitespace(prev)) {
                words++;
            }
        }
        prev = c;
    }

    if (!is_whitespace(prev)) {
        words++;
    }

    fclose(fp);

    printf("Filename: %s\n", filename);
    printf("Size (bytes): %ld\n", size);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n\n", words);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <files...>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        filestat(argv[i]);
    }

    return 0;
}
