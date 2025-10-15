#ifndef RUNNER_ARRAY_H
#define RUNNER_ARRAY_H

typedef int  (*solution_array_ro)(const int *A, int N);
typedef int  (*solution_array_rw)(int *A, int N);

int run_array_ro(solution_array_ro fn);
int run_array_rw(solution_array_rw fn);

#endif


