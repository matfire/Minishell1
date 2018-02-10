/*
** EPITECH PROJECT, 2018
** shell
** File description:
** shell
*/

#ifndef MY_SHELL
#define MY_SHELL
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

char *get_next_line(int fd);
char *get_next_line_dbg(int fd);
char **get_calls(char *str);
char **copy_env(char **envp);
char *concat_command(char *command, char *folder);
char *get_home(char **envp);
char *my_strcpy(char *src);
char *my_strcat(char *dest, char *src);
void exec_command(char **commands, char **envp);
void launch_command(char *command, char **arguments, char **envp);
void my_putstr(char *str);
void print_error(char *str);
void shift_args(char **env, int index);
int my_str_isalpha(char *str);
int is_exit(char **command);
int is_on_current(char *command);
int my_getnbr(char *str);
int my_strcmp(char *s1, char *s2);
int find_function(char **folders, char *command);
int my_strlen(char *str);
int check_builtin(char **commands, char **envp);
int is_to_unset(char *command, char *env);
#endif
