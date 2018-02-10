/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

#include "shell.h"

char **copy_env(char **envp)
{
	int size = 0;
	char **res;
	int len = 0;

	for (; envp[size] != NULL; size++);
	res = malloc(sizeof(char*) * (size + 1));
	res[size] = NULL;
	for (int i = 0; envp[i] != NULL; i++)
		res[i] = malloc(sizeof(char) * my_strlen(envp[i]) + 1);
	for (int i = 0; envp[i] != NULL; i++) {
		len = my_strlen(envp[i]);
		for (int y = 0; y < len; y++)
			res[i][y] = envp[i][y];
		res[i][my_strlen(envp[i])] = '\0';
	}
	return (res);
}

int is_exit(char **command)
{
	if (my_strcmp(command[0], "exit") == 0)
		return (1);
	return (0);
}

int my_strlen(char *str)
{
	int i = 0;
	if (str == NULL)
		return (0);
	for (; str[i] != '\0'; i++);
	return (i);
}

int is_correct_var(char *str, char *cmp)
{
	for (int i = 0; str[i] != '\0' && cmp[i] != '\0'; i++) {
		if (str[i] != cmp[i])
			return (0);
	}
	return (1);
}

void print_error(char *str)
{
	write(2, str, my_strlen(str));
}
