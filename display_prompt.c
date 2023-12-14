#include "shell.h"
/*
*print_prompt - It displays the shell prompt
*
*/
void display_prompt(void)
{
const char prompt[] = "#cisfun$ ";
int length = 0;
while (prompt[length] != '\0') length++;
write(STDOUT_FILENO, prompt, length);
}
