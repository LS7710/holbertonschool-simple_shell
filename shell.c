#include "shell.h"
#define MAX_ARGS 124

int execute_command(char *cmd) {
    char *argv[MAX_ARGS];
    int argc = 0;
    pid_t pid;
    int status;
    int i;
    int j;

    char *token = strtok(cmd, " \n\t");
    while (token != NULL && argc < MAX_ARGS - 1) {
        argv[argc++] = strdup(token);
        token = strtok(NULL, " \n\t");
    }
    argv[argc] = NULL;

    if (argv[0] == NULL) {
        return 0;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        for (j = 0; j < argc; j++) free(argv[j]);
        return EXIT_FAILURE;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Failed to execute '%s'\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    waitpid(pid, &status, 0);
    for (i = 0; i < argc; i++) free(argv[i]);

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    return 1;
}
