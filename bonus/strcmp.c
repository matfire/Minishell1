#include "criterion/criterion.h"
#include "shell.h"

Test(strcmp, simple)
{
	cr_assert_eq(my_strcmp("test", "test"), 0);
}

Test(strcmp, FALSE)
{
	cr_assert_gt(my_strcmp("test", "tast"), 0);
}

Test(strcmp, complex_test)
{
	cr_assert_gt(my_strcmp("test123", "test012"), 0);
}
