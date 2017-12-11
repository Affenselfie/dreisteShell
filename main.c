#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH  512

int main(int argc, char *argv) {
    char line[MAX_LENGTH];

    FILE *f = NULL;

    int result = 0;
    for(int i = 0;i<256;i++) {

        f = fopen("./log", "a");
        if (f == NULL) return 1;

	if(i == 0) {
	    time_t t;
	    time(&t);
	    result = fputs("LOG_START\n", f);
   	    if (result < 0) return 1;
	    result = fputs(ctime(&t), f);
   	    if (result < 0) return 1;
	}

        printf("$ ");
        if (!fgets(line, MAX_LENGTH, stdin)) break;

        result = fputs(line, f);
        if (result < 0) return 1;

        fclose(f);
    }

    fclose(f);
    return 0;
}
