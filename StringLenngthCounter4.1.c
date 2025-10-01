#include <stdio.h>
#include "mystring.h"   

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
