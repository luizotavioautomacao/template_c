#include "runner_range.h"
#include "parse.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int run_range(solution_range_fn fn){
    printf("Type l r:\n");
    int l, r;
    if(!parse_two_ints_line(&l, &r)){ fprintf(stderr, "entrada inválida\n"); exit(EXIT_FAILURE); }
    int count = 0;
    int *res = fn(l, r, &count);
    for(int i = 0; i < count; i++) printf("%d\n", res[i]);
    free(res);
    return 0;
}


