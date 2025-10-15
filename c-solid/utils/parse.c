#include "parse.h"
#include "io.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ltrim_inplace(char *s){
    while(*s && isspace((unsigned char)*s)) s++;
    return s;
}

char *rtrim_inplace(char *s){
    size_t n = strlen(s);
    while(n && isspace((unsigned char)s[n - 1])) s[--n] = '\0';
    return s;
}

bool parse_int(const char *s, int *out){
    char *end; long v = strtol(s, &end, 10);
    if(s == end || *rtrim_inplace((char*)end) != '\0') return false;
    *out = (int)v; return true;
}

int *parse_int_array_line(int n, int *out_n){
    char *line = readline();
    char *tok = strtok(line, " ");
    int *arr = xmalloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        if(!tok){ fprintf(stderr, "esperava %d ints\n", n); exit(EXIT_FAILURE); }
        if(!parse_int(tok, &arr[i])){ fprintf(stderr, "inteiro inválido: %s\n", tok); exit(EXIT_FAILURE); }
        tok = strtok(NULL, " ");
    }
    *out_n = n;
    free(line);
    return arr;
}

bool parse_two_ints_line(int *a, int *b){
    char *line = readline();
    char *tok = strtok(line, " ");
    if(!tok){ free(line); return false; }
    if(!parse_int(tok, a)){ free(line); return false; }
    tok = strtok(NULL, " ");
    if(!tok){ free(line); return false; }
    if(!parse_int(tok, b)){ free(line); return false; }
    free(line);
    return true;
}


