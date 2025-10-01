#include <stdio.h>
#include "mystring.h"

int main(int argc, char *argv[]) {
    int verbose = 0;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-v") == 0 || my_strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (my_strcmp(argv[i], "-h") == 0 || my_strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s [options] <files...>\n", argv[0]);
            printf("Options:\n  -v, --verbose  Enable verbose\n  -h, --help     Show help\n");
            return 0;
        } else {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                printf("Error: Cannot open file %s\n", argv[i]);
            } else {
                printf("File %s opened successfully\n", argv[i]);
                if (verbose) {
                    char c;
                    while ((c = fgetc(f)) != EOF) putchar(c);
                    printf("\n");
                }
                fclose(f);
            }
        }
    }

    if (verbose) printf("Verbose mode enabled.\n");
    return 0;
}
