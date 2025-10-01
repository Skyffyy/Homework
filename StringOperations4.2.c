#include <stdio.h>
#include "mystring.h"  

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <operation> <words...>\n", argv[0]);
        return 1;
    }

    char *op = argv[1];

    if (my_strcmp(op, "concat") == 0) {       
        for (int i = 2; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
    } else {
        for (int i = 2; i < argc; i++) {
            if (my_strcmp(op, "upper") == 0) {
                to_upper(argv[i]);
            } else if (my_strcmp(op, "lower") == 0) {
                to_lower(argv[i]);
            } else if (my_strcmp(op, "reverse") == 0) {
                reverse_str(argv[i]);
            }
            printf("%s", argv[i]);
            if (i < argc - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
