#include "main.h"
/**
 * join - joins string
 * @env: env
 * @len: len
 * @sym: sym
 * @name: name
 * @val: val
 */
void join(char *env, int len, char sym, char *name, char *val)
{
	int len2, i, j;

	len2 = _strlen(name);
	for (i = 0; i < len2; i++)
		env[i] = name[i];
	env[i++] = sym;
	for (j = 0; i < len; i++, j++)
		env[i] = val[j];
}
/**
 * getenv2 - true getenv func
 * @name: env var name
 * Return: string
 */
char *getenv2(char *name)
{
	char **envp, *env_var;
	int len;

	envp = environ;
	len = _strlen(name);
	while (*envp != NULL)
	{
		if (str_chk(name, *envp) == 0)
		{
			env_var = *envp + len + 1;
			return (env_var);
		}
		envp++;
	}
	return (NULL);
}
/*
void cleaner(char **envp, char **argv)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	ssize_t g;

	env(envp);
	printf("cisfun# ");
	g = getline(&buffer, &buffsize, stdin);
	if (g == -1)
		exit(1);
	buff_cleaner(buffer, g);
	tokenizer(argv, buffer, " ");
}

 * int _strncmp(char *str1, char *str2, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}
	return (1);
}
*/
