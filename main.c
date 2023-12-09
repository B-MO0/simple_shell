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
if (!parse_command(line, argv))
{
continue;
}
if (strcmp(argv[0], "exit") == 0)
{
return 0;
}
execute_command(argv);
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
