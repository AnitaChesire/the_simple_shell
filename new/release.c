#include "main.h"

void release_memory(void *pointer);
void release_memory_pointer(void **pointer);
int handle_numbers(shellinfo_t *ourtype, char *argument);
void binary_exit(shellinfo_t *ourtype, char **args);
int number(int num);

/**
 * binary_exit - A function that helps user exit the shell env.
 * @ourtype: the shell struct.
 * @args: argument passed to the shell.
 * Return: void or nothing, upon success.
 */

void binary_exit(shellinfo_t *ourtype, char **args) {
    int stat = 1;
    int status_sh;

    if (args[1] != NULL) {
        stat = handle_numbers(ourtype, args[1]);
    }

    if (stat != 0) {
        status_sh = ourtype->code_stat;
        release_memory_pointer((void **)args);
        release_memory((void *)ourtype->buf);
        release_memory((void *)ourtype->env);
        release_memory((void *)ourtype);
        exit(status_sh);
    }
}

/**
 * number - A function that counts the number of digits a given number has.
 * @num: The given number.
 * Return: The number of digits of the number counted.
 */
int number(int num)
{
	int k = 0;

	while (num != 0)
	{
		k++;
		num = num / 10;
	}

	return (k);
}
/**
 * handle_numbers - A function that helps the user control the
 * argument of exit builtin.
 * @ourtype: a pointer to the shell struct to access its types.
 * @argument: Argument of the builtin exit to be passed.
 * Return: 1 upon success, else return 0 which is negative.
 */

int handle_numbers(shellinfo_t *ourtype, char *argument)
{
	int tracer;

	tracer = atoi(argument);

	if (tracer < 0 || has_letter(argument))
	{
		ourtype->code_stat = 2;
		ourtype->error_digit = 133;
		additional_error(ourtype, argument);
		return (0);
	}

	if (tracer > 255)
	{
		ourtype->code_stat = tracer % 256;
	}
	else
	{
		ourtype->code_stat = tracer;
	}

	return (1);
}
/**
 * release_memory - A function that frees a pointer.
 * @pointer: Pointer to be freed is passed here.
 * Return: void, upon success.
 */
void release_memory(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
	pointer = NULL;
}

/**
 * release_memory_pointer - A function that frees a double pointer,
 * which is a pointer to a pointer.
 * @pointer: the pointer to a pointer to be freed.
 * Return: nothing, upon success.
 */
void release_memory_pointer(void **pointer)
{
	void **temp;

	for (temp = pointer; *temp != NULL; temp++)
	{
		release_memory(*temp);
	}

	release_memory(pointer);
}

