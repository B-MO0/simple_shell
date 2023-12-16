#include "shell.h"

/**
* run_shell - shell infinite loop.
* Return: status
*/
int run_shell(void)
{
char *line = NULL;
char *argv[MAX_ARGS];

while (1)
{
display_prompt();
read_command(&line);

if (!parse_command(line, argv))
{
free(line);
line = NULL;
continue;
}

if (strcmp(argv[0], "exit") == 0)
{
free(line);
return (0);
}

if (strcmp(argv[0], "env") == 0)
{
print_env();
free(line);
line = NULL;
continue;
}

execute_command(argv);
free(line);
line = NULL;
}
}

void signal_handler(int signo) {
if (signo == SIGINT) {
cleanup();
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS);
}
}

int main(void)
{
if (signal(SIGINT, signal_handler) == SIG_ERR) {
write(STDERR_FILENO, "Cannot catch SIGINT\n", 19);
}

return run_shell();
}
