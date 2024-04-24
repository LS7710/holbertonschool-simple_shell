#include "shell.h"
#include <sys/wait.h>

void execute_command(char *cmd)
{
    char *argv[10];
    int i = 0;
    pid_t pid;
    int status;

    argv[i] = strtok(cmd, " \n");
    while (argv[i] != NULL && i < 9) {
        argv[++i] = strtok(NULL, " \n");
    }

    if (argv[0]) {
        if (strcmp(argv[0], "exit") == 0) {
            free(cmd);
            exit(0);
        }

        pid = fork();
        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("hsh");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("hsh");
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Command exited with status: %d\n", exit_status);
            }
        }
    }
}

