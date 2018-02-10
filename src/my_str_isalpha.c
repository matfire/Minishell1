/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** is str alpha?
*/

int my_str_isalpha(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (!(str[i] > 64 && str[i] < 91)
		    && !(str[i] > 96 && str[i] < 123)
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		else
			i++;
	}
	return (1);
}
