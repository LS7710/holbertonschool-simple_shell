#include "library.h"
#define ARR_SIZE 64
/**
 * remove_nl - for remove \n when not need it
 *
 * @cmd: command to execute
 * Return: cmd
 */
char *remove_nl(char *cmd)
{
        int x;

        for (x = 0; cmd[x] != '\n'; x++)
        {
        }
        cmd[x] = '\0';

        return (cmd);
}
/**
 * get_cmd - For recive the command
 *
 * @cmd: command to execute
 *
 * Return: cmd
 */
char *get_cmd(char *cmd)
{
        int check = 0;
        size_t len = 0;

        if (isatty(STDIN_FILENO))/*if interactive use $ */
        {
                printf("$ ");
        }
        check = getline(&cmd, &len, stdin);/*when use command save on variable cmd*/
        if (check == -1)/*when error occure*/
        {
                if (isatty(STDIN_FILENO))
                {
                        perror("getline");
                        free(cmd);
                        return (NULL);
                }
                free(cmd);
                exit(EXIT_SUCCESS);
        }
        cmd = remove_nl(cmd);/* see funcion */

        return (cmd);
}
/**
 * execute_command - fix child and parent process
 * @cmd: command to execute
 *
 * Return: 0
 */
void execute_command(char *cmd)
{
        int status;
        pid_t pid = fork();
        char *arg[ARR_SIZE];
        int i = 0;
        char *cmd_name = NULL;
	char *envp[] { NULL }

        cmd_name = strtok(cmd, " ");/*use for space and add arguments*/

        while (cmd_name != NULL && i < ARR_SIZE - 1)
        {
		arg[i] = cmd_name;
                cmd_name = strtok(NULL, " ");
                i++;
        }

        arg[i] = NULL;

        if (pid < 0)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)/*CHILD PROCESS*/
        {
                if (execvp(cmd_name, arg) == -1)
                {
                        perror("execvp");
                        exit(EXIT_FAILURE);
                }
        }
        else/*Parent Process*/
        {
                if (waitpid(pid, &status, 0) == -1)
                {
                        perror("waitpid");
                        exit(EXIT_FAILURE);
                }
        }
}
/**
 * main - enter and exit shell
 *
 *
 *
 * Return: 0
 */
int main(void)
{
        char *cmd = NULL;
        char *token;

        while (1)
        {
                cmd = get_cmd(cmd);

                token = strtok(cmd, " ");/*cut the string to the first insta done*/

                if (strcmp(token, "exit") == 0)/*token is same but not space*/
                {
                        free(cmd);
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        execute_command(token);
                }
                free(cmd);
        }
        return (0);
}
