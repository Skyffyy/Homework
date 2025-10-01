#include <stdio.h>
#include <stdlib.h>
#include "mynumber.h"  

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
