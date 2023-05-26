#include<stdio.h>
#include<stdlib.h>
/**
 * main - entry point
 * @argc: no. of arg
 * @argv: string of characters
 * @envp: array
 * Return: 0 (succes)
 */
int main(int argc, char *argv[], char *envp[])
{
int i = 0;
(void)argc;
(void)argv;
while (envp[i] != NULL)
{
printf("%s\n", envp[i]);
i++;
}
return (0);
}
