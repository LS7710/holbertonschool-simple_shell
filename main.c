#include "library.h"
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
 * Return: cmd
 */
char *get_cmd(void)
{
	char *cmd = NULL;
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

	arg[i] = strtok(cmd, " ");/*use for space and add arguments*/

	while (arg[i] != NULL)
	{
		i++;
		arg[i] = strtok(NULL, " ");
	}
	arg[i] = NULL;
	if (pid < 0)
	{
		perror("fork");
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)/*CHILD PROCESS*/
	{
		if (execvp(arg[0], arg) < 0)
		{
			perror("execvp");
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else/*Parent Process*/
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			free(cmd);
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
	char *cmd;

	while (1)
	{
		cmd = get_cmd();

		if (strcmp(cmd, "exit") == 0)/*compara is exit*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		else
		{
			execute_command(cmd);
		}
		free(cmd);
	}
	return (0);
}
