#ifndef TESTS_H
#define TESTS_H

#define NBR_PADDING 4
#define FN_PADDING 12

#include "libft.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void test_passed(const char *str);
void test_failed(const char *str);

void test_isalpha();
void test_isdigit();
void test_isalnum();
void test_isascii();
void test_isprint();
void test_strlen();
void test_memset();

#endif //TESTS_H
