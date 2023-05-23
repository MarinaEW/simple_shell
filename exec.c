#include "shell.h"
/**
 * execmd - fn. used to handle command execution
 * @argv: string handling arguements
 */
void execmd(char **argv)
{
char *commands = NULL;
char *real_command = NULL;

if (argv)
{
/* get the command */
commands = argv[0];

/* generate the path to this command before passing it to execve */
real_command = get_location(commands);

/* execute the actual command with execve */
if (execve(real_command, argv, NULL) == -1){
perror("./shell");
}
}   
}
