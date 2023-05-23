#include "shell.h"
/**
 * main - entry point
 * @argc: no. of characters
 * @argv: array of characters
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
char *prompt = "cisfun$ ";
char *ptr = NULL;
size_t n = 0;
ssize_t char_no;
char *ptr_copy = NULL;
const char *delim = " \n";
int token_no = 0;
char *token;
int i = 0;
(void)argc; /*declaring void variables*/
/*Create infinite loop*/
while (1)
{
printf("%s", prompt);
char_no = getline(&ptr, &n, stdin);
if (char_no == -1)/*check if getline fn.fails or reached EOF or using CTRL+D*/
{
printf("Exiting\n");
return (-1);
}
ptr_copy = malloc(sizeof(char) * char_no);/*alloc. space for a cpy of ptr*/
if (ptr_copy == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}	/*split (ptr) string into an array of words*/
strcpy(ptr_copy, ptr);/*cpy ptr to ptr_copy*/
token = strtok(ptr, delim);/*cal. the total no.of tokens*/
while (token != NULL)
{
token_no++;
token = strtok(NULL, delim);
}
token_no++; /*Allocate space to hold the array of strings*/
argv = malloc(sizeof(char *) * token_no);/*Store each token in the argv*/
token = strtok(ptr_copy, delim);
if (token != NULL)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, delim);
i++;
}
argv[i] = NULL;
execmd(argv);/*execute the command*/
}
free(ptr);/*free up allocated memory*/
free(ptr_copy);
return (0);
}
