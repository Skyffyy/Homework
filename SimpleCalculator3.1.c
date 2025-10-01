#include <stdio.h>
#include "mystring.h"   

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }

    int num1 = my_atoi(argv[1]);   
    int num2 = my_atoi(argv[3]);
    char op = argv[2][0];
    int result;

    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2; break;
        default:
            printf("Error: Unknown operator '%c'\n", op);
            return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}
