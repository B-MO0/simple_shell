#include "shell.h"
/**
* run_shell - shell infinite loop.
*/
int run_shell()
{
char line[MAX_LINE];
char *argv[MAX_ARGS];
while (1)
{
display_prompt();
read_command(line);
}
}

/**
* main - run the shell
* Return: status
*/
int main()
{
return run_shell();
}
