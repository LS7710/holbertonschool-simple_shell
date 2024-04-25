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

            fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
            exit(127);
	} else if (pid < 0) {
            perror("fork failed");
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
