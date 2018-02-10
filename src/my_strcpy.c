/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** copies string into another
*/

#include "shell.h"

char *my_strcpy(char *src)
{
	int i = 0;
	char *dest;

	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
