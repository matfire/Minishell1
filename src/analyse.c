/*
** EPITECH PROJECT, 2018
** analyse
** File description:
** analyse
*/

#include "shell.h"

int find_function(char **folders, char *command)
{
	DIR *dip;
	struct dirent *entry;

	for (int i = 0; folders[i] != NULL; i++) {
		dip = opendir(folders[i]);
		if (dip == NULL)
			continue;
		while ((entry = readdir(dip)) != NULL) {
			if (my_strcmp(entry->d_name, command) == 0)
				return (i);
		}
		closedir(dip);
	}
	if (!access(command, X_OK))
		return (900);
	return ((is_on_current(command)) ? 900 : 400);
}

int is_home(char *str)
{
	if (str[0] == 'H' && str[1] == 'O' && str[2] == 'M' && str[3] == 'E')
		return (1);
	return (0);
}

char *get_home(char **envp)
{
	int index = 4;
	char *res;
	int i = 0;
	int placement = 0;

	for (; envp[placement] != 0; placement++) {
		if (is_home(envp[placement]))
			break;
	}
	res = malloc(sizeof(char) * my_strlen(envp[placement]));
	for (i = 0; envp[placement][index] != '\0'; i++) {
		res[i] = envp[placement][index];
		index++;
	}
	res[i] = '\0';
	return (res);
}

int is_to_unset(char *command, char *env)
{
	int i = 0;

	if (env == NULL || command == NULL)
		return (0);
	while (env[i] != '=' && env[i] != '\0') {
		if (env[i] == command[i])
			i++;
		else
			return (0);
	}
	return (1);
}
