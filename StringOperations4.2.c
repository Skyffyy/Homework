#include <stdio.h>
#include <string.h>

void to_upper(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') *str = *str - ('a' - 'A');
        str++;
    }
}

void to_lower(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') *str = *str + ('a' - 'A');
        str++;
    }
}

void reverse_str(char *str) {
    int len = 0;
    while (str[len]) len++;
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int main(int argc, char *argv[]) {
    char *op = argv[1];

    if (strcmp(op, "concat") == 0) {
        for (int i = 2; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
    } else {
        for (int i = 2; i < argc; i++) {
            if (strcmp(op, "upper") == 0) {
                to_upper(argv[i]);
            } else if (strcmp(op, "lower") == 0) {
                to_lower(argv[i]);
            } else if (strcmp(op, "reverse") == 0) {
                reverse_str(argv[i]);
            }
            printf("%s", argv[i]);
            if (i < argc - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
