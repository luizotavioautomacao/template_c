#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xmalloc(size_t n){
    void *p = malloc(n);
    if(!p){ perror("malloc"); exit(EXIT_FAILURE); }
    return p;
}

void *xrealloc(void *p, size_t n){
    void *q = realloc(p, n);
    if(!q){ perror("realloc"); exit(EXIT_FAILURE); }
    return q;
}

void die_if_null(const void *p){
    if(!p){ fprintf(stderr, "null ptr\n"); exit(EXIT_FAILURE); }
}

char *readline(void){
    size_t cap = 128, len = 0;
    char *buf = xmalloc(cap);
    for(;;){
        if(!fgets(buf + len, (int)(cap - len), stdin)) break;
        len += strlen(buf + len);
        if(len > 0 && buf[len - 1] == '\n'){ buf[len - 1] = '\0'; break; }
        cap <<= 1;
        buf = xrealloc(buf, cap);
    }
    return buf;
}


