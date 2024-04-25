#include "shell.h"
#define MAX_ARGS 124

int execute_command(char *cmd) {
    char *argv[10];
    int i = 0;
    pid_t pid;
    int status;
    int j;
    int k;
    int f;


    char *token = strtok(cmd, " ");
    while (token != NULL && i < 9) {
        argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;

    if (argv[0] == NULL) {

        for (j = 0; j < i; j++) free(argv[j]);
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);

        for (f = 0; f < i; f++) free(argv[f]);
        return WEXITSTATUS(status);
    } else {
        perror("fork");

        for (k = 0; k < i; k++) free(argv[k]);
        return EXIT_FAILURE;
    }
}

