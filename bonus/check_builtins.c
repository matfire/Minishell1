#include "shell.h"
#include <criterion/criterion.h>

Test(check_builtin, FALSE)
{
	char *command[2];

	command[0] = "ls";
	cr_assert_eq(check_builtin(command, NULL), 0);
}

Test(check_builtin, cd)
{
	char *command[2];

	command[0] = "cd";
	cr_assert_eq(check_builtin(command, NULL), 1);
}
