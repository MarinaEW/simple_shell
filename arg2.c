#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/**
 * main - fn. that handles command line with arg.
 * @argc: no. of arg
 * @argv: char. in a string
 * Return: 0 (sucess)
 */
int main(int argc, char **argv)
{
size_t n = 0;
char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
char *delim = " ";
int i = 0;
argc = 0;
*argv = 0;

printf("$ ");
if (getline(&cmd, &n, stdin) == -1)
	return (-1);
cmd_cpy = strdup(cmd);
token = strtok(cmd, delim);
while (token)
{
token = strtok(NULL, delim);
argc++;
}
argv = malloc(sizeof(char *) * argc);
token = strtok(cmd_cpy, delim);
while (token)
{
argv[i] = token;
token = strtok(NULL, delim);
i++;
}
argv[i] = 0;
i = 0;
while (argv[i])
{
printf("%s\n", argv[i++]);
}
free(cmd);
free(cmd_cpy);
free(argv);
return (0);
}
