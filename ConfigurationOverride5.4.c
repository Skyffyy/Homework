#include <stdio.h>
#include "mystring.h"
#include "mynumber.h"

int main(int argc, char *argv[]) {
    int port = 8080;
    char host[100] = "localhost";
    int debug = 0;

    char *files[100];
    int file_count = 0;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-p") == 0 || my_strcmp(argv[i], "--port") == 0) {
            if (i+1 >= argc) { printf("Error: %s requires number\n", argv[i]); return 1; }
            if (!parse_int(argv[i+1], &port)) { printf("Invalid port: %s\n", argv[i+1]); return 1; }
            i++;
        } else if (my_strcmp(argv[i], "--host") == 0) {
            if (i+1 >= argc) { printf("Error: %s requires address\n", argv[i]); return 1; }
            int j=0; while(argv[i+1][j] && j<99){ host[j]=argv[i+1][j]; j++; } host[j]=0;
            i++;
        } else if (my_strcmp(argv[i], "-d") == 0 || my_strcmp(argv[i], "--debug") == 0) {
            debug = 1;
        } else if (argv[i][0] == '-') {
            printf("Unknown flag: %s\n", argv[i]); return 1;
        } else {
            files[file_count++] = argv[i];
        }
    }

    printf("Configuration:\nPort: %d\nHost: %s\nDebug: %s\n", port, host, debug?"true":"false");

    for (int i=0;i<file_count;i++){
        FILE *f = fopen(files[i], "r");
        if(!f){ printf("Cannot open file: %s\n", files[i]); continue; }
        printf("File: %s\n", files[i]);
        char c;
        while((c=fgetc(f))!=EOF) putchar(c);
        printf("\n");
        fclose(f);
    }

    return 0;
}
