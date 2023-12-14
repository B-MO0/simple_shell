#include "shell.h"
/*
*display_prompt - It displays the shell prompt
*
*/
void display_prompt(void)
{
const char prompt[] = "YOUR_COMMAND$ ";
int length = 0;
while
(prompt[length] != '\0') length++;
write(STDOUT_FILENO, prompt, length);
}
