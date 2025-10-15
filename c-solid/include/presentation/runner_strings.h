#ifndef RUNNER_STRINGS_H
#define RUNNER_STRINGS_H

#include <stdbool.h>

typedef bool (*solution_strings_fn)(const char *a, const char *b, int n);

int run_strings(solution_strings_fn fn);

#endif


