#include <stdio.h>
#include <stdlib.h>



#define MAX_LENGTH  512

int main(int argc, char *argv) {
    char line[MAX_LENGTH];

    FILE *f = fopen("./log", "a");

    if (f == NULL) {
        return 1;
    }

    int accessCount = 0;
    while (1) {
        accessCount++;


        printf("$ ");
        if (!fgets(line, MAX_LENGTH, stdin)) break;

        int result = fputs(line, f);

        if (result < 0) return 1;

        if (accessCount % 5 == 0) {
            fclose(f);
            f == NULL;

            f = fopen("./log", "a");
            if (f == NULL) return 1;



        } else if (accessCount > 256) {
            fclose(f);

            return 0;
        }

    }

    if (f != NULL) fclose(f);

    return 0;
}