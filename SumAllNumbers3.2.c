#include <stdio.h>
#include "mystring.h"   
#include "mynumber.h"   

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
