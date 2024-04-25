#include "shell.h"
#define MAX_ARGS 124

int execute_command(char *cmd) {
    char *argv[10];
    int argc = 0;
    pid_t pid;
    int status;

    char *token = strtok(cmd, " \n\t");
    while (token != NULL && argc < 10 - 1) {
        argv[argc++] = token;
        token = strtok(NULL, " \n\t");
    }
    argv[argc] = NULL;

    if (argv[0] == NULL) {
        return 0;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (pid == 0) {

        execvp(argv[0], argv);
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        exit(127);
    }


    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    return EXIT_SUCCESS;
}
