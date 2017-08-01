//
// Created by Mu$t4f△ J4m4L on 7/8/17.
//

#include "minunit.h"   // the framework


char *test_dlopen()
{
	return NULL;
}

char *test_function()
{
	return NULL;
}

char *test_failures()
{
	return NULL;
}

char *test_dlclose()
{
	retutn NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_dlopen);
	mu_run_test(test_function);
	mu_run_test(test_failures);
	mu_run_test(test_dlclose);

	return NULL;
}

RUN_TESTS(all_tests);