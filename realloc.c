#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@ch: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *ch, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ch[i] = b;
	return (ch);
}

/**
 * ffree - frees a string of strings
 * @ff: string of strings
 */
void ffree(char **ff)
{
	char **a = ff;

	if (!ff)
		return;
	while (*ff)
		free(*ff++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ch;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	ch = malloc(new_size);
	if (!ch)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (ch);
}
