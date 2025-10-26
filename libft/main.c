#include "tests.h"

void test_passed(const char *str){ printf("\e[032m[OK]\e[0m%s", str); }
void test_failed(const char *str){ printf("\e[031m[KO]\e[0m%s", str); }

int main()
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
}