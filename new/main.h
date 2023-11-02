#ifndef MAIN_H

#define MAIN_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define COMMAND_MAX_LENGTH 1024

extern char **environ;

#define _CMD_NOT_EXISTS_ "Not found"
#define _EACCES_ "Permission denied"
#define _ENOENT_ "No such file or directory"
#define _ILLEGAL_NUMBER_ "Illegal number"

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	int pid;
	int num_cmd;
	int cur_path;
	int it_mode;
	int code_stat;
	int error_digit;
	char *cmd;
	char *cmd_path;
	char *buf;
	char **the_arguments;
	char *env;
} shellinfo_t;

typedef struct __attribute__((__packed__))
{
	char *msg;
	int password;
} issue_t;

typedef struct __attribute__((__packed__))
{
	char *cmd;
	void (*func)(shellinfo_t *ourtype, char **arguments);
} sysFunction_t;

char *_getenv(const char *name);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int pid_func(void);
int ppid(void);
char *custom_strtok(char *string, const char *delimiter);
void modify_env(char *buffer);
char *handle_comments(char *command);
char *find_file_path(char *path, char *cmd);

char *stringify(int numbe);
int has_letter(char *string);
int is_numeric(unsigned int number);
char *merge_words(char *w1, char *w2, char *w3, const char *del);
char *select_message(int error_code);
int output_to_fd(char *message, int file_des);
int display_error(char *message);
void additional_error(shellinfo_t *ourtype, char *more);
int number(int num);
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
char *path_func(char *cmd);
char *path_builder(const char *dir, const char *command);
void exec(char **argv, char *program_name);
char **tokenize_command(char *command);
void env_func(void);
char **strtok_cmd(char *command);
int isatty(int fd);
int cd_func(char *argv[]);
size_t _strlen(const char *str);
int custom_strcmp(const char *s1, const char *s2);

#endif
