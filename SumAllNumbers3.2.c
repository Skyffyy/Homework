#include <stdio.h>

int my_atoi(const char *str) {
    int result = 0, sign = 1;
    if (*str == '-') { sign = -1; str++; }
    else if (*str == '+') { str++; }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return sign * result;
}

int is_number(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (*str == '\0') return 0;
    while (*str) {
        if (*str < '0' || *str > '9') return 0;
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        if (is_number(argv[i])) {
            sum += my_atoi(argv[i]);
        } else {
            printf("Warning: '%s' is not a valid number, skipping.\n", argv[i]);
        }
    }

    printf("Sum: %d\n", sum);
    return 0;
}
