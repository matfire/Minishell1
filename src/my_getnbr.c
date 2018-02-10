/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** str to int
*/

int my_getnbr(char *str)
{
	int res = 0;

	for (int i = 0; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';
	return (res);
}
