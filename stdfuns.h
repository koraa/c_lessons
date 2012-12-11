/**
 * Frequently needet standart definitions.
 *
 * Author: Karolin Varner
 * Date:   6.12.2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define loop for(;;)
#define loopn(v) int v=0; for(;;v++)
#define loopi(v,m) int v = 0; for(; v < m ; v++ )

#define mputc(C) fputc( C , stdout)
#define mputs(s) fputs( s , stdout)
#define puti(i) printf("%d", i)
#define putiln(i) printf("%d\n", i)

#define mgeti(s, v) int v; mputs( s ); scanf("%d", &v)

#define false 0
#define true  1

#define STR_IMAXLEN 50

char* itostr(int i, size_t *len) {
    char* buf =  malloc( (STR_IMAXLEN+1) * sizeof(char) );
    snprintf(buf, STR_IMAXLEN, "%i", i);
    *len = strlen(buf);
    buf = realloc(buf, (*len) * sizeof(char));
    return buf;
}

void fill(int no, char c) {
    for (int i = 0; i < no; i++)
        mputc(c);
}

int randrng(int a, int  b) {
    return rand() % abs(b-a) + a;
}
