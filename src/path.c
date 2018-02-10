/*
** EPITECH PROJECT, 2018
** path
** File description:
** executes commands
*/

#include "shell.h"

int get_folder_length(char *str, int index)
{
	int i = index;

	for (; str[i] != ':' && str[i] != '\0'; i++);
	return (i);
}
int get_words_colons(char *str)
{
	int n = 1;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ':' || str[i] == '\0')
			n++;
	return (n);
}
char **split_by_semicolons(char *path)
{
	char **res;
	int n = 0;
	int m = 0;

	res = malloc(sizeof(char*) * (get_words_colons(path) + 1));
	res[get_words_colons(path)] = NULL;
	for (n = 0; path[n] != '='; n++);
	n = n + 1;
	for (int i = 0; i < get_words_colons(path); i++) {
		res[i] = malloc(sizeof(char) * get_folder_length(path, n) + 1);
		for (m = 0; path[n] != ':' && path[n] != '\0'; n++) {
			res[i][m] = path[n];
			m++;
		}
		n++;
		res[i][m] = '\0';
	}
	return (res);
}

char **find_path(char **envp)
{
	char **res;

	for (int i = 0; envp[i] != 0; i++) {
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
		&& envp[i][2] == 'T' && envp[i][3] == 'H')
			res = split_by_semicolons(envp[i]);
	}
	return (res);
}

void exec_command(char **commands, char **envp)
{
	char **command_folders = find_path(envp);
	int index = find_function(command_folders, commands[0]);

	if (index == 400) {
		my_putstr(commands[0]);
		my_putstr(": Command not found.\n");
		return;
	}
	else if (index == 900) {
		launch_command(commands[0], commands, envp);
		return;
	}
	commands[0] = concat_command(commands[0], command_folders[index]);
	launch_command(commands[0], commands, envp);
	for (int i = 0; command_folders[i] != 0; i++)
		free(command_folders[i]);
	free(command_folders);
}
