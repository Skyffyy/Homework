#include <stdio.h>

int my_strlen(const char *str) {
    int len = 0;
    while (str[len]) len++;
    return len;
}

int contains_word(const char *haystack, const char *needle) {
    int hlen = my_strlen(haystack);
    int nlen = my_strlen(needle);
    if (nlen == 0) return 1;

    for (int i = 0; i <= hlen - nlen; i++) {
        int match = 1;
        for (int j = 0; j < nlen; j++) {
            char hc = haystack[i + j];
            char nc = needle[j];
            if (hc >= 'A' && hc <= 'Z') hc += ('a' - 'A');
            if (nc >= 'A' && nc <= 'Z') nc += ('a' - 'A');
            if (hc != nc) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int found_any = 0;
    for (int i = 2; i < argc; i++) {
        if (contains_word(argv[i], argv[1])) {
            printf("%s\n", argv[i]);
            found_any = 1;
        }
    }
    if (!found_any) {
        printf("No occurrences found.\n");
    }
    return 0;
}
