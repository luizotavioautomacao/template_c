#ifndef IO_H
#define IO_H

#include <stddef.h>

char *readline(void);
void  die_if_null(const void *p);
void *xmalloc(size_t n);
void *xrealloc(void *p, size_t n);

#endif


