#include "tests.h"

void test_isprint()
{
	int file = open("failed.log", O_WRONLY | O_CREAT);

	printf("%-*s : ", FN_PADDING, "ft_isprint");
	short unsigned int number = 0;
	short unsigned int passed = 0;
	for (short int i = -128; i < 256; i++)
	{
		if (ft_isprint(i) == isprint(i)) { passed++; }
		else { dprintf(file, "ft_isprint(%d)\n", i); }
		number++;
	}
	close(file);
	if (passed == number) { test_passed(""); }
	else { test_failed(""); }
	printf(" (%*d / %*d)\n", NBR_PADDING, passed, NBR_PADDING, number);
}