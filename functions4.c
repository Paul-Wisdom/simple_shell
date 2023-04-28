#include "main.h"
/**
 * check_space - checks if a buffer contains only space
 * @str: buffer
 * Return: o if true else 1
 */
int check_space(char *str)
{
	int i, len = 0;

	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
	}
	return (0);
}
