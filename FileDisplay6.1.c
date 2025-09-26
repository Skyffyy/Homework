#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./display <file1> <file2> ...\n");
        return 1;
    }

    int i;
    char buffer[1024];  

    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("Error opening file %s\n", argv[i]);
            continue;
        }

        printf("File: %s\n", argv[i]);

        while (fgets(buffer, sizeof(buffer), f) != NULL) {
            printf("%s", buffer);
        }

        fclose(f);
        printf("\n");  
    }

    return 0;
}
