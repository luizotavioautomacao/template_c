#ifndef RUNNER_RANGE_H
#define RUNNER_RANGE_H

typedef int* (*solution_range_fn)(int l, int r, int *count_out);

int run_range(solution_range_fn fn);

#endif


