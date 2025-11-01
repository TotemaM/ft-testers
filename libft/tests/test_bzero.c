#include "tests.h"

void test_bzero()
{
	printf("%-*s : ", FN_PADDING, "ft_bzero");

	unsigned char number = 2;
	unsigned char passed = 0;

	char c[9] = "abcdefgh";
	char d[9] = "abcdefgh";

	ft_bzero(c, 1); bzero(d, 1);
	if (strcmp(c, d) == 0) { passed++; }

	//ft_bzero(c, -1); bzero(d, -1);
	//if (strcmp(c, d) == 0) { passed++; }

	ft_bzero(c, 7); bzero(d, 7);
	if (strcmp(c, d) == 0) { passed++; }

	if (passed == number) { test_passed(""); }
	else { test_failed(""); }
	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}