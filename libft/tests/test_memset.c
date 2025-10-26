#include "tests.h"

void test_memset()
{
	printf("%-*s : ", FN_PADDING, "ft_memset");

	unsigned char number = 3;
	unsigned char passed = 0;

	// Segfault because Read Only Memory
	//char *a = ft_memset("abcdefgh", 'a', 1);
	//char *b = memset("abcdefgh", 'a', 1);

	char c[9] = "abcdefgh";
	char d[9] = "abcdefgh";

	ft_memset(c, 'a', 1); memset(d, 'a', 1);
	if (strcmp(c, d) == 0) { passed++; }

	ft_memset(c, -42, 1); memset(d, -42, 1);
	if (strcmp(c, d) == 0) { passed++; }

	ft_memset(c, -42, 8); memset(d, -42, 8);
	if (strcmp(c, d) == 0) { passed++; }

	if (passed == number) { test_passed(""); }
	else { test_failed(""); }
	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}