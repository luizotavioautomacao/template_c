#include <stdbool.h>
#include <string.h>

bool solution_strings(const char *a, const char *b, int n){
    int cnt[256] = {0};
    for(int i = 0; i < n; i++){ cnt[(unsigned char)a[i]]++; cnt[(unsigned char)b[i]]--; }
    for(int c = 0; c < 256; c++) if(cnt[c] != 0) return false;
    return true;
}


