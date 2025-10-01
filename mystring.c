#include <stdio.h>
#include "mystring.h"

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

int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void to_upper(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') *str = *str - ('a' - 'A');
        str++;
    }
}

void to_lower(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') *str = *str + ('a' - 'A');
        str++;
    }
}

void reverse_str(char *str) {
    int len = 0;
    while (str[len]) len++;
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
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

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return (int)(s1[i]) - (int)(s2[i]);
        i++;
    }
    return (int)(s1[i]) - (int)(s2[i]);
}

int parse_int(const char *s, int *out) {
    int i = 0;
    int sign = 1;
    int val = 0;

    if (s[0] == '-') {
        sign = -1;
        i++;
    }
    if (s[i] == '\0') return 0;

    for (; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
        val = val * 10 + (s[i] - '0');
    }
    *out = val * sign;
    return 1;
}

int is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}