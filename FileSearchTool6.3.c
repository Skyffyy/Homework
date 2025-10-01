#include <stdio.h>
#include "mystring.h"

int contains_word(const char *line, const char *word, int case_insensitive) {
    int len_line = my_strlen(line);
    int len_word = my_strlen(word);
    if (len_word == 0) return 1;

    for (int i = 0; i <= len_line - len_word; i++) {
        int match = 1;
        for (int j = 0; j < len_word; j++) {
            char c1 = line[i + j];
            char c2 = word[j];
            if (case_insensitive) {
                if (c1 >= 'A' && c1 <= 'Z') c1 += 'a' - 'A';
                if (c2 >= 'A' && c2 <= 'Z') c2 += 'a' - 'A';
            }
            if (c1 != c2) { match = 0; break; }
        }
        if (match) return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int case_insensitive = 0;
    int arg_start = 1;

    if (argc < 3) {
        printf("Usage: %s [-i] <word> <files...>\n", argv[0]);
        return 1;
    }

    if (my_strcmp(argv[1], "-i") == 0) {
        case_insensitive = 1;
        arg_start++;
    }

    char *word = argv[arg_start];

    for (int i = arg_start + 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) { 
            printf("Cannot open file: %s\n", argv[i]); 
            continue; 
        }

        char buffer[1024];
        int line_no = 0;
        while (fgets(buffer, sizeof(buffer), f)) {
            line_no++;
            if (contains_word(buffer, word, case_insensitive)) {
                printf("%s:%d:%s", argv[i], line_no, buffer);
            }
        }

        fclose(f);
    }

    return 0;
}
