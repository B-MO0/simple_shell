#include "shell.h"
/*
*print_prompt - It displays the shell prompt
*
*/
void display_prompt(void)
{
const char *prompt = "#cisfun$ ";
write(STDOUT_FILENO, prompt, strlen(prompt));
}
