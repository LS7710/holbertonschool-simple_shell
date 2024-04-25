#include <unistd.h>
#include "shell.h"

void remove_newline(char* line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
        i++;
    }
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int last_status = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        remove_newline(line);

	last_status = execute_command(line);
    }

    free(line);
    return last_status;
}
