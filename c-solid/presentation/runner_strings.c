#include "runner_strings.h"
#include "io.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run_strings(solution_strings_fn fn){
    printf("Digite n:\n");
    char *nline = readline(); int n;
    if(!parse_int(nline, &n)){ fprintf(stderr, "n inválido\n"); exit(EXIT_FAILURE); }
    free(nline);

    printf("Digite anagrama:\n");     char *a = readline();
    printf("Digite permutação:\n");   char *b = readline();

    if((int)strlen(a) < n || (int)strlen(b) < n){ fprintf(stderr, "tamanho insuficiente\n"); exit(EXIT_FAILURE); }

    bool ok = fn(a, b, n);
    printf("%d\n", ok ? 1 : 0);

    free(a); free(b);
    return 0;
}


