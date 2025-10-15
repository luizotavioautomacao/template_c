#include "runner_array.h"
#include "parse.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

static int read_n(void){
    printf("Digite o tamanho do vetor:\n");
    char *nline = readline();
    int n; if(!parse_int(nline, &n)){ fprintf(stderr, "N inválido\n"); exit(EXIT_FAILURE); }
    free(nline);
    return n;
}

int run_array_ro(solution_array_ro fn){
    int n = read_n();
    int parsed_n = 0;
    int *arr = parse_int_array_line(n, &parsed_n);
    int ret = fn(arr, parsed_n);
    printf("%d\n", ret);
    free(arr);
    return 0;
}

int run_array_rw(solution_array_rw fn){
    int n = read_n();
    int parsed_n = 0;
    int *arr = parse_int_array_line(n, &parsed_n);
    int ret = fn(arr, parsed_n);
    printf("%d\n", ret);
    free(arr);
    return 0;
}


