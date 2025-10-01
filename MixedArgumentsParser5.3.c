#include <stdio.h>
#include "mystring.h"
#include "mynumber.h"

int main(int argc, char *argv[]) {
    int verbose = 0;
    int number = 0;
    char *output_file = NULL;
    char *files[100];
    int file_count = 0;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-v") == 0) verbose = 1;
        else if (my_strcmp(argv[i], "-n") == 0) {
            if (i+1 >= argc) { printf("Error: -n requires a number\n"); return 1; }
            if (!parse_int(argv[i+1], &number)) { printf("Invalid number: %s\n", argv[i+1]); return 1; }
            i++;
        } else if (my_strcmp(argv[i], "-o") == 0) {
            if (i+1 >= argc) { printf("Error: -o requires filename\n"); return 1; }
            output_file = argv[i+1];
            i++;
        } else if (argv[i][0] == '-') {
            printf("Unknown flag: %s\n", argv[i]);
            return 1;
        } else {
            files[file_count++] = argv[i];
        }
    }

    if (verbose) printf("Verbose enabled.\nNumber: %d\nOutput file: %s\n", number, output_file ? output_file : "none");

    for (int i = 0; i < file_count; i++) {
        FILE *f = fopen(files[i], "r");
        if (!f) { printf("Cannot open file: %s\n", files[i]); continue; }
        printf("File: %s\n", files[i]);
        char c;
        while ((c = fgetc(f)) != EOF) putchar(c);
        printf("\n");
        fclose(f);
    }

    return 0;
}
