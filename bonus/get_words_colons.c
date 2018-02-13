#include "shell.h"
#include <criterion/criterion.h>

int get_words_colons(char *str);

Test(get_words_colons, simple)
{
	char *colons;

	colons = "1:2:2:3:4";
	cr_assert_eq(get_words_colons(colons), 5);
}

Test(get_words_colons, long_string)
{
	char *colons;

	colons = "5:6:4:6:4:6:3:21:3:1:8:976:54:6:4";
	cr_assert_eq(get_words_colons(colons), 15);
}

Test(get_words_colons, short_string)
{
	char *colons;

	colons = "2:3:1:4";
	cr_assert_eq(get_words_colons(colons), 4);
}
