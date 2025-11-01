#include "tests.h"

void test_memcpy()
{
	printf("%-*s : ", FN_PADDING, "ft_memcpy");
	unsigned char number = 1;
	unsigned char passed = 0;

	char ref[12] = "abcdefghijk";
	char a[12]; char b[12];

	ft_memcpy(a, ref, 12); memcpy(b, ref, 12);
	if (strcmp(a, b) == 0) { passed++; }

	if (passed == number) { test_passed(""); }
	else { test_failed(""); }

	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}