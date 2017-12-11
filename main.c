#include <stdio.h>
#include <stdlib.h>


#define MAX_LENGTH  512

int main(int argc, char *argv) {
    char line[MAX_LENGTH];

    FILE *f = fopen("./log", "a");

    if (f == NULL) {
        return 1;
    }

    int *test = malloc(sizeof(int));


    int result = fputs("LOG_START\n", f);
    if (result < 0) return 1;

    int accessCount = 0;
    while (1) {
        accessCount++;


        printf("$ ");
        if (!fgets(line, MAX_LENGTH, stdin)) break;

        result = fputs(line, f);
        if (result < 0) return 1;


        fclose(f);


        f = fopen("./log", "a");
        if (f == NULL) return 1;


        if (accessCount > 256) {
            fclose(f);

            return 0;
        }

    }

    fclose(f);

    return 0;
}