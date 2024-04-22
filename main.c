#include "librery.h"
/*
 * main - make the shell work
 */
int main(void)
{
	char cmd[128];

	while(1)
	{
		printf("$ ");
		getline("%s", cmd);

	if (strcmp(cmd, "exit") == 0)
		break;
	else
	{
		
	}	

return (0);	
}
