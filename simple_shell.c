#include "shell.h"
/**
 * main - entry point
 * @argc: no. of characters
 * @argv: array of characters
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	char *prompt = "#cisfun$ ", *buff = NULL, read;
	size_t n = 0;
	bool from_pipe = false;
	pid_t pid;
	(void)argc;
	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		write(STDIN_FILENO, prompt, 9);
		read = getline(&buff, &n, stdin);
		if (read == -1)
		{
			perror("Error from getline\n");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[read - 1] == '\n')
			buff[read - 1] = '\0';
		argv[0] = buff;
		pid = fork();
		if (pid == -1)
		{
			perror("Error from fork\n");
			exit(EXIT_FAILURE);
		}
		argv[0] = buff;
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
	}
	free(buff);
	return (0);
}
