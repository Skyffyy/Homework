#include <stdio.h>
#include <stdlib.h>

int is_valid_base(int base) {
    return base == 2 || base == 8 || base == 10 || base == 16;
}
void convert_to_base(int number, int base) {
    char buffer[65];  
    const char *digits = "0123456789ABCDEF";
    int is_negative = 0;
    int i = 0;

    if (number == 0) {
        printf("0\n");
        return;
    }

    if (number < 0 && base == 10) {
        is_negative = 1;
        number = -number;
    }

    while (number > 0) {
        buffer[i++] = digits[number % base];
        number /= base;
    }

    if (is_negative) {
        buffer[i++] = '-';
    }

    for (int j = i - 1; j >= 0; j--) {
        putchar(buffer[j]);
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./converter <number> <from_base> <to_base>\n");
        return 1;
    }

    int from_base = atoi(argv[2]);
    int to_base = atoi(argv[3]);

    if (!is_valid_base(from_base) || !is_valid_base(to_base)) {
        printf("Error: Supported bases are 2, 8, 10, and 16.\n");
        return 1;
    }

    char *endptr;
    int number = strtol(argv[1], &endptr, from_base);

    if (*endptr != '\0') {
        printf("Error: Invalid number '%s' for base %d.\n", argv[1], from_base);
        return 1;
    }

    convert_to_base(number, to_base);
    return 0;
}
