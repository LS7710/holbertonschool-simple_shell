#include "shell.h"

int execute_command(char *cmd) {
    char *argv[10];
    int i = 0;
    pid_t pid;
    int status = 0;

    argv[i] = strtok(cmd, " \n");
    while (argv[i] != NULL && i < 9) {
        argv[++i] = strtok(NULL, " \n");
    }

    if (argv[0]) {
        pid = fork();
        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                fprintf(stderr, "%s: %s: command not found\n", argv[0], strerror(errno));
                exit(127);
            }
        } else if (pid < 0) {
            perror("hsh");
            return EXIT_FAILURE;
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                return WEXITSTATUS(status);
            }
        }
    }
    return EXIT_SUCCESS;
}
