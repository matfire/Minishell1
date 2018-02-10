/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "shell.h"

int main(int ac, char **av, char **envp)
{
	char *command;
	char **command_call;
	char **env_backup = copy_env(envp);

	if (ac != 1 && av[1] != NULL)
		return (84);
	while (1) {
		if (isatty(0))
			write(1, "$>", 2);
		command = get_next_line(0);
		if (command == NULL)
			exit(0);
		command_call = get_calls(command);
		if (is_exit(command_call))
			exit((command_call[1] != NULL) ? my_getnbr(command_call[1]) : 0);
		if (check_builtin(command_call, env_backup))
			continue;
		exec_command(command_call, env_backup);
		free(command);
		for (int i = 0; command_call[i] != 0; i++)
			free(command_call[i]);
		free(command_call);
	}
	envp = copy_env(env_backup);
	return (0);
}
