#include "shell.h"

/**
* print_env - Prints all the environment variables.
* @env: the environment.
*/
void print_env(void)
{
int i = 0;
while (environ[i])
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
