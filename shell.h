#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
void execmd(char **argv);
char *get_location(char *commands);

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
char *_strcpy(char *dest, char *src);
char *_strdup(const char *string);
void _puts(char *s);
int _putchar(char ch);

/* toem_atoi.c */
int interactive(info_t *info);
int is_delim(char ch, char *delim);
int _isalpha(int alpha);
int _atoi(char *string);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_dec(int, int);
char *conv_number(long int, int, int);
void rm_comments(char *);

/* toem_errors.c */
void _eputs(char *s);
int _eputchar(char c);
int _putfd(char ch, int fd);
int _putsfd(char *string, int fd);

/* toem_builtin.c */
int _myexit(info_t *infor);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **head, const char *string, int n);
list_t *add_node_end(list_t **head, const char *string, int num);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_p);

/* toem_environ.c */
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

/* toem_string.c */
int _strlen(char *ch);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *stack, const char *needle);
char *_strcat(char *dest, char *src);

/* toem_getenv.c */
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

/* toem_realloc.c */
char *_memset(char *ch, char b, unsigned int n);
void ffree(char **ff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* toem_lists1.c */
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char str);
ssize_t get_node_index(list_t *head, list_t *node);

/* toem_errors1.c */
int _erratoi(char *str;
void print_error(info_t *info, char *estr);
int print_d(int input, int fdes);
char *convert_number(long int in, int base, int flags);
void remove_comments(char *buf);

#endif
