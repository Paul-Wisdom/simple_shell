#include "main.h"
/**
 * exit1 - exit
 * @num: num
 */
void exit1(int num)
{
	exit(num);
}
/**
 * str_cnp - checks if strings are the same
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if true else 1
 */
int str_cnp(char *str1, char *str2)
{
	int len1 = 0, len2 = 0, i;

	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;
	if (len1 != len2)
		return (1);
	for (i = 0; i < len1; i++)
	{
		if (str1[i] != str2[i])
			return (1);

	}
	return (0);
}
/**
 * str_cpy - copies strring
 * @str: string
 * Return: string
 *
char *str_cpy(char *str)
{
	char *res;
	int len = 0, i;

	while (str[len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		res[i] = str[i];
	return (str);
}
*/
/**
 * _strlen - finds length of string
 * @str: the string
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _set - sets env variable
 * @name: name
 * @value: value
 * Return: 0 for success els 1
 */
char *_set(char *name, char *value, char *env_var)
{
	size_t len;
//	char *env_var;
	char **ptr;

	if (env_var)
		free (env_var);
	len = _strlen(name) + _strlen(value) + 2;
	env_var = malloc(len * sizeof(char));
	if (env_var == NULL)
	{
		free (env_var);
		return (NULL);
	}
	join(env_var, len, '=', name, value);
	ptr = environ;
	while (*ptr != NULL)
	{
		if (str_chk(name, *ptr) == 0)
		{
			*ptr = env_var;
			return (env_var);
		}
		ptr++;
	}
	free (env_var);
//	free (ptr);
	return (NULL);
}
char *_memcpy(char *str2)
{
	int i, len;
	char *str1;

	len = _strlen(str2);
	str1 = malloc(sizeof(char) * (len + 1));
	if (!str1)
	{
		free (str1);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
	return (str1);
}
