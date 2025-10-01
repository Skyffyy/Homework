#include <stdio.h>
#include "mystring.h"  

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <word> <strings...>\n", argv[0]);
        return 1;
    }

    int found_any = 0;
    for (int i = 2; i < argc; i++) {
        if (contains_word(argv[i], argv[1])) {   
            printf("%s\n", argv[i]);
            found_any = 1;
        }
    }

    if (!found_any) {
        printf("No occurrences found.\n");
    }

    return 0;
}
