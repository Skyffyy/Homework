#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return (int)(s1[i]) - (int)(s2[i]);
        i++;
    }
    return (int)(s1[i]) - (int)(s2[i]);
}

void print_help() {
    printf("Help: Usage: ./program [-v|--verbose] [-h|--help] [files...]\n");
}

int main(int argc, char *argv[]) {
    int verbose = 0;

    int i = 1;
    while (i < argc) {
        if (my_strcmp(argv[i], "-v") == 0 || my_strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
            i++;
        } else if (my_strcmp(argv[i], "-h") == 0 || my_strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else {
            if (verbose) {
                printf("Processing file: %s\n", argv[i]);
            } else {
                printf("%s\n", argv[i]);
            }
            i++;
        }
    }

    if (verbose) {
        printf("Verbose mode is enabled.\n");
    }

    return 0;
}
