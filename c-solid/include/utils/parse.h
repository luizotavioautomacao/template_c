#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>
#include <stddef.h>

bool parse_int(const char *s, int *out);
bool parse_two_ints_line(int *a, int *b);
int  *parse_int_array_line(int n, int *out_n);
char *ltrim_inplace(char *s);
char *rtrim_inplace(char *s);

#endif


