#include <stdio.h>
#include "mystring.h"   
#include "mynumber.h"   

int main(int argc, char *argv[]) {
    int sum = 0, count = 0;
    int min = 0, max = 0;
    int first_valid = 1;

    for (int i = 1; i < argc; i++) {
        if (is_number(argv[i])) {        
            int val = my_atoi(argv[i]);   
            sum += val;
            if (first_valid) {
                min = max = val;
                first_valid = 0;
            } else {
                if (val < min) min = val;
                if (val > max) max = val;
            }
            count++;
        } else {
            printf("Warning: '%s' is not a valid number, skipping.\n", argv[i]);
        }
    }

    if (count == 0) {
        printf("No valid numbers provided.\n");
        return 1;
    }

    printf("Count: %d\n", count);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (double)sum / count);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
