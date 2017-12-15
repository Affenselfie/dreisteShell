#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define MAX_LENGTH  512

int main(int argc, char *argv) {
    char line[MAX_LENGTH];

    FILE *f = NULL;



    int result = 0;
    for (int i = 0; i < 256; i++) {


        f = fopen("./log", "a");
        if (f == NULL) return 1;

        if (i == 0) {
            time_t *t = malloc(sizeof(time_t));
            time(t);
            result = fputs("LOG_START\n", f);
            if (result < 0) return 1;
            result = fputs(ctime(t), f);
            free(t);
            t = NULL;
            if (result < 0) return 1;

        }

        printf("$ ");
        if (!fgets(line, MAX_LENGTH, stdin)) break;


        result = fputs(line, f);
        if (result < 0) return 1;

        int comp_result = strcmp(line, "exit\n");
        if (comp_result == 0) return 0;

        fclose(f);
    }

    fclose(f);
    return 0;
}
