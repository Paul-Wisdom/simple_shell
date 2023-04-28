#include "main.h"
/**
 * str_chk - checks if string1 starts string2
 * @str1: string 1
 * @str2: string 2
 * Return: o if same else 1
 */
int str_chk(char *str1, char *str2)
{
	int i = 0, len = 0, j;

	while (str1[len])
		len++;
	for (i = 0; i < len; i++)
	{
		if ((str1[i] == str2[i]) && str2[len] == '=')
			j = 0;
		else
		{
			j = 1;
			break;
		}
	}

	return (j);

}
