#include <unistd.h>
#include "shell.h"

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int status = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        status = execute_command(line);
    }

    free(line);
    return status;
}
