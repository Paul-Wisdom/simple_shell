#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
/**
 * main - a simple shell
 * @argc: arg count
 * @arg: cmd args
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **arg)
{
	int status, e, space;
	ssize_t g;
	size_t buffsize = 0;
	char  *buffer = NULL;
	pid_t child_pid;
	char *argv[1024];
	char **envp;
	int s = 1;
	char *path2, *temp = NULL, *path = NULL, *env_var = NULL, *temp2 = NULL;

	while (s > 0)
	{
		envp = environ;
		printf("$ ");
		g = getline(&buffer, &buffsize, stdin);
		if (g == -1)
			exit(1);
		buff_cleaner(buffer, g);
		space = check_space(buffer);
		if (space == 0)
			continue;
		tokenizer(argv, buffer, " ");
		path = _set("PATH", "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", env_var);
		path2 = getenv2("PATH");
		temp = _memcpy(argv[0]);
		argv[0] = path_searcher(argv[0], path2);
		if (str_cnp(temp, "exit") == 0)
		{
			free(argv[0]);
			free(path);
			free(env_var);
			free(temp);
			free(buffer);
			exit1(0);
		}
		else if (argv[0] == NULL)
			error_print(arg[0], temp, s);
		else
		{
			if (command_checker(argv[0]) == -1)
				error_print(arg[0], temp, s);
			else
			{
				child_pid = fork();
				if (child_pid == -1)
					return (1);
				if (child_pid == 0)
				{
					e = execve(argv[0], argv, envp);
					if (e == -1)
						return (1);
				}
				else
				{
					wait(&status);
				}
			}
		}
		s++;
		if (space != 0)
		{
			free(argv[0]);
			free(temp);
			free(env_var);
		}
	}
	return (0);
}
/**
 * env - copies the env variable
 * @envp: env var
 * Return: env variables
 */
char **env(char **envp)
{
	int i = 0;

	while (environ[i])
	{
		envp[i] = environ[i];
		i++;
	}
	return (envp);
}
/**
 * buff_cleaner - removes trailing newline char
 * @buffer: literally
 * @num: num of chars in the buffer
 * Return: cleaned buffer
 */
char *buff_cleaner(char *buffer, ssize_t num)
{
	if (buffer[num - 1] == '\n')
	{
		buffer[num - 1] = '\0';
		--num;
	}
	return (buffer);
}
/**
 * tokenizer - splits a string into tokens
 * @arg: array of tokens
 * @buffer: the array of strings
 * @sep: the seperating char
 * Return: an array of tokens
 */
char **tokenizer(char **arg, char *buffer, char *sep)
{
	char *token;
	int i = 0;

	token = strtok(buffer, sep);
	while (token)
	{
		arg[i] = token;
		token = strtok(NULL, sep);
		i++;
	}
	arg[i] = NULL;
	return (arg);
}
void free_func(char *buffer, char **envp __attribute__((unused)))
{
	free (buffer);
}
