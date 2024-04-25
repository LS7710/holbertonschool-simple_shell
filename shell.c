#include "shell.h"

int execute_command(char *cmd) {
    char *argv[10];
    int i = 0;
    pid_t pid;
    int status;


    argv[i] = strtok(cmd, " \t");
    while (argv[i] != NULL && i < 9) {
        argv[++i] = strtok(NULL, " \t");
    }
    argv[i] = NULL;

    if (argv[0]) {
        pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);
            fprintf(stderr, "Failed to execute '%s'\n", argv[0]);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork failed");
        } else {
            waitpid(pid, &status, 0);
        }
    }
    return WEXITSTATUS(status);
}

