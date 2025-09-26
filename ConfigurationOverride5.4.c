#include <stdio.h>

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

int main(int argc, char *argv[]) {
    int port = 8080;
    char host[100] = "localhost";
    int debug = 0;

    int i = 1;
    while (i < argc) {
        if (my_strcmp(argv[i], "--port") == 0 || my_strcmp(argv[i], "-p") == 0) {
            if (i + 1 >= argc) {
                printf("Error: %s requires a number\n", argv[i]);
                return 1;
            }
            int val;
            if (!parse_int(argv[i + 1], &val)) {
                printf("Invalid port number: %s\n", argv[i + 1]);
                return 1;
            }
            port = val;
            i += 2;
        } else if (my_strcmp(argv[i], "--host") == 0 || my_strcmp(argv[i], "-h") == 0) {
            if (i + 1 >= argc) {
                printf("Error: %s requires an address\n", argv[i]);
                return 1;
            }
            int j = 0;
            while (argv[i + 1][j] != '\0' && j < 99) {
                host[j] = argv[i + 1][j];
                j++;
            }
            host[j] = '\0';
            i += 2;
        } else if (my_strcmp(argv[i], "--debug") == 0 || my_strcmp(argv[i], "-d") == 0) {
            debug = 1;
            i++;
        } else if (argv[i][0] == '-') {
            printf("Unknown flag: %s\n", argv[i]);
            return 1;
        } else {
            printf("Ignoring unknown argument: %s\n", argv[i]);
            i++;
        }
    }

    printf("Configuration:\n");
    printf("Port: %d\n", port);
    printf("Host: %s\n", host);
    printf("Debug: %s\n", debug ? "true" : "false");

    return 0;
}
