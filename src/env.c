/*
** EPITECH PROJECT, 2018
** env
** File description:
** env
*/

#include "shell.h"

void shift_args(char **env, int index)
{
	int i = index + 1;
	if (env[0] == NULL)
		return;
	for (; env[i] != NULL; i++) {
		env[index] = my_strcpy(env[i]);
		index++;
	}
	env[index] = NULL;
}

int is_on_current(char *command)
{
	DIR *dip;
	struct dirent *entry;
	char *convert;

	dip = opendir(".");
	convert = malloc(sizeof(char) * my_strlen(command));
	for (int i = 0, y = 2; command[y] != '\0'; i++, y++)
		convert[i] = command[y];
	convert[my_strlen(command) - 1] = '\0';
	while ((entry = readdir(dip)) != NULL) {
		if (my_strcmp(entry->d_name, convert) == 0)
			return (1);
	}
	return (0);
}
