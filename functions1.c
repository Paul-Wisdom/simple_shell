#include "main.h"
/**
 * path_searcher - looks for a command in the env path
 * @command: the command
 * @path: the path
 * Return: path to the command
 */
char *path_searcher(char *command, char *path)
{
	struct stat st;
	char *token = NULL, *file = NULL, *file2 = NULL;

	if (stat(command, &st) == 0)
		return (command);
	token = strtok(path, ":");
	while (token != NULL)
	{
		file = strjoin(token, "/");
		if (!file)
			break;
		file2 = strjoin(file, command);
		free (file);
		if (file2 == NULL)
			break;
		if (stat(file2, &st) == 0)
			return (file2);
		else
			free (file2);
		token = strtok(NULL, ":");
	}
//	free (file);
//	free (file2);
	free (token);
	return (NULL);
}

/**
 * strjoin - joins two strings
 * @str1: string 1
 * @str2: string 2
 * Return: the concatenated string
 */
char *strjoin(char *str1, char *str2)
{
	int len1 = 0, len2 = 0, i;
	char *res;

	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
	{
		free (res);
		return (NULL);
	}
	for (i = 0; i < len1; i++)
		res[i] = str1[i];
	for (i = 0; i < len2; i++)
	{
		res[len1] = str2[i];
		len1++;
	}
	res[len1] = '\0';
	return (res);
}

/**
 * strcheck - checks if a string contains a character
 * @str: the string
 * @ch: the char
 * Return: 0 if true and 1 otherwise
 */
int strcheck(char *str, char *ch)
{
	int len = 0;

	while (str[len])
	{
		if (str[len] == *ch)
			return (0);
		len++;
	}
	return (1);
}
/**
 * command_checker - checks if command is valid
 * @argv: the command args
 * @env: the command environment
 * Return: -1 if invalid, 0 otherwise
 */
int command_checker(char *argv)
{
	int e;

	e = access(argv, X_OK);
	if (e == -1)
		return (e);
	return (0);
}
/**
 * error_print - prints error message
 * @arg: name of program
 * @command: the command
 * @id: process id
 */
void error_print(char *arg, char *command, int id)
{
	if (strcheck(command, "/") == 1)
		printf("%s: %d: %s: not found\n", arg, id, command);
	else
	{
		if (access(command, W_OK | R_OK) == 0)
			printf("%s: %d: %s: Permission denied\n", arg, id, command);
		else
		{
			printf("%s: %d: %s: not found\n", arg, id, command);
		}
	}
}
