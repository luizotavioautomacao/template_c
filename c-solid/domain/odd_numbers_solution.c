#include <stdlib.h>

int* solution_range(int l, int r, int *count_out){
    if(l > r){ *count_out = 0; return NULL; }
    int count = 0;
    for(int x = l; x <= r; x++) if(x % 2 != 0) count++;
    int *res = malloc(sizeof(int) * count);
    int i = 0;
    for(int x = l; x <= r; x++) if(x % 2 != 0) res[i++] = x;
    *count_out = count;
    return res;
}


