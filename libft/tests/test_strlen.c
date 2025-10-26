#include "tests.h"

void test_strlen()
{
	printf("%-*s : ", FN_PADDING, "ft_strlen");

	unsigned char number = 5;
	unsigned char passed = 0;

	if (ft_strlen("") == strlen("")) { passed++; }
	if (ft_strlen("42") == strlen("42")) { passed++; }
	if (ft_strlen("42\0test") == strlen("42\0test")) { passed++; }
	if (ft_strlen("Hello World") == strlen("Hello World")) { passed++; }
	
	char str[10000]; str[9999] = 0;
	if (ft_strlen(str) == strlen(str)) { passed++; }

	if (passed == number) { test_passed(""); }
	else { test_failed(""); }
	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}