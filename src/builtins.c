/*
** EPITECH PROJECT, 2018
** builtins
** File description:
** calls substitutes for builtins functions
*/

#include "shell.h"

void call_env(char **envp)
{
	if (envp[0] == NULL)
		return;
	for (int i = 0; envp[i] != 0; i++) {
		my_putstr(envp[i]);
		write(1, "\n", 2);
	}
}

void call_setenv(char **commands, char **envp)
{
	int size = 0;
	char *res;

	if (!my_str_isalpha(commands[1])) {
		my_putstr("setenv: Variable name must contain ");
		my_putstr("alphanumeric characters.\n");
	}
	if (envp[0] == NULL)
		return;
	res = malloc(sizeof(char) * (my_strlen(commands[1]) + my_strlen(commands[2]) + 2));
	for (; envp[size] != NULL; size++) {
		if (is_to_unset(commands[1], envp[size])) {
			res = my_strcpy(commands[1]);
			res = my_strcat(res, "=");
			if (commands[2] != NULL)
				res = my_strcat(res, commands[2]);
			envp[size] = my_strcpy(res);
			return;
		}
	}
	res = my_strcpy(commands[1]);
	res = my_strcat(res, "=");
	if (commands[2] != NULL)
		res = my_strcat(res, commands[2]);
	envp[size] = my_strcpy(res);
	envp[size + 1] = NULL;
}

void call_unsetenv(char **commands, char **envp)
{
	if (commands[1] == NULL) {
		my_putstr("unsetenv: Too few arguments.\n");
		return;
	}
	if (envp[0] == NULL)
		return;
	for (int i = 0; envp[i] != NULL; i++) {
		if (is_to_unset(commands[1], envp[i])) {
			shift_args(envp, i);
			return;
		}
	}
}

void call_cd (char **commands, char **envp)
{
	int len = 0;
	static char *cwd;

	if (cwd == NULL) {
		cwd = malloc(sizeof(char) * 4000);
		getcwd(cwd, 4000);
	}
	for (; commands[len] != 0; len++);
	if (len > 2)
		print_error("cd: Too many arguments.\n");
	else if (commands[1] == NULL)
		chdir(get_home(envp));
	else if (commands[1][0] == '-') {
		chdir(cwd);
		free(cwd);
	} else if (commands[1][0] == '~')
		chdir(get_home(envp));
	else if (chdir(commands[1]) == -1) {
		print_error(commands[1]);
		print_error(": No such file or directory.\n");
	}
}

int check_builtin(char **commands, char **envp)
{
	if (my_strcmp(commands[0], "env") == 0) {
		call_env(envp);
		return (1);
	} else if (my_strcmp(commands[0], "setenv") == 0 && envp != NULL) {
		call_setenv(commands, envp);
		return (1);
	} else if (my_strcmp(commands[0], "unsetenv") == 0 && envp != NULL) {
		call_unsetenv(commands, envp);
		return (1);
	} else if (my_strcmp(commands[0], "cd") == 0) {
		call_cd(commands, envp);
		return (1);
	}
	return (0);
}
