#include "tests.h"

void test_isdigit()
{
	int file = open("failed.log", O_WRONLY | O_CREAT);

	printf("%-*s : ", FN_PADDING, "ft_isdigit");
	short unsigned int number = 0;
	short unsigned int passed = 0;
	for (short int i = -128; i < 256; i++)
	{
		if (ft_isdigit(i) == isdigit(i)) { passed++; }
		else { dprintf(file, "ft_isdigit(%d)\n", i); }
		number++;
	}
	close(file);
	if (passed == number) { test_passed(""); }
	else { test_failed(""); }
	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}