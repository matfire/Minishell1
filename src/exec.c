/*
** EPITECH PROJECT, 2018
** exec
** File description:
** handles command executions
*/

#include "shell.h"

char *concat_command(char *command, char *folder)
{
	char *res;
	int index = 0;
	int len_com = my_strlen(command);
	int len_fold = my_strlen(folder);

	res = malloc(sizeof(char) * (len_com + len_fold + 2));

	for (int i = 0; folder[i] != '\0'; i++) {
		res[index] = folder[i];
		index++;
	}
	res[index] = '/';
	index++;
	for (int i = 0; command[i] != '\0'; i++) {
		res[index] = command[i];
		index++;
	}
	res[index] = '\0';
	return (res);
}

void launch_command(char *command, char **arguments, char **envp)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid > 0) {
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status)) {
			my_putstr(strsignal(WTERMSIG(status)));
			write(1, "\n", 1);
		}
	} else if (pid < 0) {
		my_putstr(strerror(errno));
	} else {
		execve(command, arguments, envp);
		kill(pid, SIGTERM);
	}
}
