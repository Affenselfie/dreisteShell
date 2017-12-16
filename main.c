#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <unistd.h>

#define MAX_LENGTH 512

void SIGINTHandler(int);

FILE *f = NULL;
int result = 0;

int main(int argc, char *argv) {
    char line[MAX_LENGTH];
    register struct passwd *pw;
    register uid_t uid;

    uid = geteuid ();
    pw = getpwuid (uid);

    //Register SIGINTHANDLER
     signal(SIGINT, SIGINTHandler);

    // Open File and write Log Start
    f = fopen("./log", "a");
    if (f == NULL) return 1;

    time_t *t = malloc(sizeof(time_t));
    time(t);
    result = fputs("LOG_START\n", f);
    if (result < 0) return 1;
    result = fputs(ctime(t), f);
    if (result < 0) return 1;


    printf("[%s@%s %s] $ ", pw->pw_name, "hostname", "~");
    // "Fake" Terminal and log input
    while(fgets(line, MAX_LENGTH, stdin) != NULL) {
        result = fputs(line, f);
        if (result < 0) return 1;

        int comp_result = strcmp(line, "exit\n");
        if (comp_result == 0) break;

        printf("[%s@%s %s] $ ", pw->pw_name, "hostname", "~");
    }

    time(t);
    result = fputs("LOG_END at ", f);
      if (result < 0) return 1;
    result = fputs(ctime(t), f);
      if (result < 0) return 1;
    fclose(f);
    return 0;
}

void SIGINTHandler(int signal) {
  time_t *t = malloc(sizeof(time_t));
  time(t);
  result = fputs("LOG_END at ", f);
    if (result < 0) exit(1);
  result = fputs(ctime(t), f);
    if (result < 0) exit(1);
  fclose(f);
  exit(0);
}
