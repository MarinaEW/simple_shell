#include "shell.h"
/**
 * main - entry point
 * @argc: no. of characters
 * @argv: array of characters
 * @env: returns the environment
 * Return: 0 (success)
 */
int main(int argc, char *argv[], char **env)
{
	char *prompt = "#cisfun$ ";
	char *buff = NULL;
	size_t n = 0;
	char read;
	bool from_pipe = false;
	char read_copy;
	pid_t pid;
	(void)argc;
	(void)env;
	(void)read_copy;
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
				perror("./shell");
		}
		else
			wait(NULL);
	}
	free(buff);
	return (0);
}
