#include <stdio.h>


#define MAX_LENGTH  1024

int main(int argc, char *argv) {
    char line[MAX_LENGTH];

    FILE *f =fopen("./log", "a");

    if(f==NULL){
        return 1;
    }

    while (1) {


        printf("$ ");
        if (!fgets(line, MAX_LENGTH, stdin)) break;

        int result = fputs(line, f);

        if (result < 0) return 1;



    }

    fclose(f);

    return 0;
}