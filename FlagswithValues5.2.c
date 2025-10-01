#include <stdio.h>
#include "mystring.h"
#include "mynumber.h"

int main(int argc, char *argv[]) {
    int verbose = 0;
    int number = 0;
    char *output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-v") == 0) verbose = 1;
        else if (my_strcmp(argv[i], "-n") == 0) {
            if (i + 1 >= argc) { printf("Error: -n requires a number\n"); return 1; }
            if (!parse_int(argv[i+1], &number)) { printf("Invalid number: %s\n", argv[i+1]); return 1; }
            i++;
        } else if (my_strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) { printf("Error: -o requires filename\n"); return 1; }
            output_file = argv[i+1];
            i++;
        } else {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                printf("Cannot open file: %s\n", argv[i]);
            } else {
                printf("Processing file: %s\n", argv[i]);
                if (verbose) {
                    char c;
                    while ((c = fgetc(f)) != EOF) putchar(c);
                    printf("\n");
                }
                fclose(f);
            }
        }
    }

    if (verbose) printf("Verbose enabled.\n");
    printf("Number: %d\n", number);
    if (output_file) printf("Output file: %s\n", output_file);

    return 0;
}
