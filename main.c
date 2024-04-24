#include <unistd.h>
#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *prompt = "$ ";
    int last_status = 0;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf("%s", prompt);
        }

        read = getline(&line, &len, stdin);
        if (read == -1) {
            break;
        }

        last_status = execute_command(line);
    }

    free(line);
    return last_status;
}

