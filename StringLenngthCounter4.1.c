#include <stdio.h>

int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int main(int argc, char *argv[]) {
    int total = 0;
    for (int i = 1; i < argc; i++) {
        int len = my_strlen(argv[i]);
        printf("%s %d\n", argv[i], len);
        total += len;
    }
    printf("Total %d\n", total);
    return 0;
}
