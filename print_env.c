#include "shell.h"

/* i use extern because the environ variable is stored in sys std libraries*/
extern char **environ;

/**
* print_env - Prints all the environment variables.
*/
void print_env(void)
{
for (int i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
