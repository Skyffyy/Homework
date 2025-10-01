#include <stdio.h>
#include "mystring.h"  /

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <word> <files...>\n", argv[0]);
        return 1;
    }

    char *word = argv[1];

    for (int i = 2; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) { 
            printf("Cannot open file: %s\n", argv[i]); 
            continue; 
        }

        char buffer[1024];
        int line_no = 0;
        while (fgets(buffer, sizeof(buffer), f)) {
            line_no++;
            if (contains_word(buffer, word)) { 
                printf("%s:%d:%s", argv[i], line_no, buffer);
            }
        }

        fclose(f);
    }

    return 0;
}
