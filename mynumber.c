#include <stdio.h>
#include "mynumber.h"

int is_number(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (*str == '\0') return 0;
    while (*str) {
        if (*str < '0' || *str > '9') return 0;
        str++;
    }
    return 1;
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