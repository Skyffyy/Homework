#include <stdio.h>
#include "mystring.h" 

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
