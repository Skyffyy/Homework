#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return (int)(s1[i]) - (int)(s2[i]);
        i++;
    }
    return (int)(s1[i]) - (int)(s2[i]);
}

int parse_int(const char *s, int *out) {
    int i = 0;
    int sign = 1;
    int val = 0;

    if (s[0] == '-') {
        sign = -1;
        i++;
    }
    if (s[i] == '\0') return 0;

    for (; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
        val = val * 10 + (s[i] - '0');
    }
    *out = val * sign;
    return 1;
}

int main(int argc, char *argv[]) {
    int verbose = 0;
    int number = 0;
    char *output = NULL;
    int i = 1;

    while (i < argc) {
        if (my_strcmp(argv[i], "-v") == 0) {
            verbose = 1;
            i++;
        } else if (my_strcmp(argv[i], "-n") == 0) {
            if (i + 1 >= argc) {
                printf("Error: -n requires a number\n");
                return 1;
            }
            if (!parse_int(argv[i + 1], &number)) {
                printf("Invalid number: %s\n", argv[i + 1]);
                return 1;
            }
            i += 2;
        } else if (my_strcmp(argv[i], "-o") == 0) {
            if (i + 1 >= argc) {
                printf("Error: -o requires a filename\n");
                return 1;
            }
            output = argv[i + 1];
            i += 2;
        } else if (argv[i][0] == '-') {
            printf("Unknown flag: %s\n", argv[i]);
            return 1;
        } else {
            // filename: try open
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                printf("Error opening file %s\n", argv[i]);
            } else {
                if (verbose) {
                    printf("Input file %s opened successfully.\n", argv[i]);
                } else {
                    printf("%s\n", argv[i]);
                }
                fclose(f);
            }
            i++;
        }
    }

    if (verbose) {
        printf("Verbose mode enabled.\n");
        printf("Number set to: %d\n", number);
        if (output) printf("Output file: %s\n", output);
        else printf("No output file specified.\n");
    }

    return 0;
}
