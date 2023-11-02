#include "main.h"

int is_numeric(unsigned int number);
char *merge_words(char *w1, char *w2, char *w3, const char *del);
char *select_message(int error_code);
int output_to_fd(char *message, int file_des);

/**
 * output_to_fd - A function that prints a string to file descriptor
 * @message: instead of character a string is printed.
 * @file_des: File descriptor to print to either 1, 2 or 0.
 * Return: On success numbers of bytes printed is returned.
 */
int output_to_fd(char *message, int file_des)
{
	int buffer;

	buffer = strlen(message);
	return (write(file_des, message, buffer));
}

/**
 * merge_words - Joins three words with a delimiter separator.
 * @w1: Word1 to join.
 * @w2: Word2 to join.
 * @w3: Word3 to join.
 * @del: Separator between the words.
 * Return: A string containing strings joined together.
 */
char *merge_words(char *w1, char *w2, char *w3, const char *del)
{
	int total_size;
	char *joint;

    w1 = (w1 != NULL) ? w1 : "";
    w2 = (w2 != NULL) ? w2 : "";
    w3 = (w3 != NULL) ? w3 : "";

    total_size = strlen(w1) + strlen(del) + strlen(w2) + strlen(del) + strlen(w3) + 2;

    joint = malloc(total_size);
    if (joint == NULL)
    {
        return NULL;
    }

    strcpy(joint, w1);
    strcat(joint, del);
    strcat(joint, w2);
    strcat(joint, del);
    strcat(joint, w3);
    strcat(joint, "\n");

    return joint;
}

/**
 * select_message - Checks for error code and selects a matching message.
 * @error_code: The error code to match.
 * Return: A pointer to the error message.
 */
char *select_message(int error_code)
{
	int i, num_messages;

    static const struct {
        int code;
        const char *message;
    } error_messages[] = {
        {_ENOENT_, "No such file or directory"},
        {_EACCES_, "Permission denied"},
        {_CMD_NOT_EXISTS_, "Command not found"},
        {_ILLEGAL_NUMBER_, "Illegal number"},
    };

    num_messages = sizeof(error_messages) / sizeof(error_messages[0]);

    for (i = 0; i < num_messages; i++)
    {
        if (error_code == error_messages[i].code)
        {
            return (char *)error_messages[i].message;
        }
    }

    return "";
}
/**
 * is_numeric - A function that checks if a given parameter is a digit.
 * @number: Number to be checked.
 * Return: 1 if it is a number, 0 otherwise.
 */
int is_numeric(unsigned int number)
{
		return (number >= '0' && number <= '9');
}

