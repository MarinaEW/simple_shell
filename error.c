#include "shell.h"

/**
 *_eputs - prints an input string
 * @s: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *s)
{
	int n = 0;

	if (!s)
		return;
	while (s[n] != '\0')
	{
		_eputchar(s[n]);
		n++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @ch: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char ch, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (ch != BUF_FLUSH)
		buf[k++] = ch;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @string: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int fd)
{
	int n = 0;

	if (!string)
		return (0);
	while (*string)
	{
		n += _putfd(*string++, fd);
	}
	return (n);
}
