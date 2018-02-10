#include <criterion/criterion.h>
#include <stdlib.h>
#include "shell.h"
char **split_by_semicolons(char *path);

Test(find_function, TRUE)
{
	char **env;

	env = split_by_semicolons(getenv("PATH"));
	cr_assert_lt(find_function(env, "ls"), 900);
}

Test(find_function, FALSE)
{
	char **env;

	env = split_by_semicolons(getenv("PATH"));
	cr_assert_eq(find_function(env, "ms"), 400);
}
