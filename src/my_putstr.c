/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putstr
*/

#include "shell.h"

void my_putstr(char *str)
{
	int len = my_strlen(str);

	write(1, str, len);
}
