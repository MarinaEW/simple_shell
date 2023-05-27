#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * gomain: entry fn.
 * @argv: stirng of arg.
 * @argc: no. of arg.
 */
int gomain(int argc, char *argv[])
{
int i = 1;
int j = 0;
/*Check if there are any arguments passed*/
if (argc == 1)
{
write(STDOUT_FILENO, "No arguments passed.\n", strlen("No arguments passed.\n"));
}
else
{
/*Print all the arguments*/
write(STDOUT_FILENO, "Arguments passed:\n", strlen("Arguments passed:\n"));
if (i < argc)
{
write(STDOUT_FILENO, argv[i], strlen(argv[i]));
write(STDOUT_FILENO, ":", 1);

while (argv[i][j] != '\0')
{
write(STDOUT_FILENO, &argv[i][j], 1);
write(STDOUT_FILENO, " ", 1);
j++;
}
i++;
write(STDOUT_FILENO, "\n", 1);
}
}
return (0);
}
