/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** append s2 to s1
*/

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int y = 0;

	while (dest[i] != '\0')
		i++;
	while (src[y] != '\0') {
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}
