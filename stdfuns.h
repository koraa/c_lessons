/**
 * Frequently needet standart definitions.
 *
 * Author: Karolin Varner
 * Date:   6.12.2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define loop for(;;)

#define mputc(C) fputc( C , stdout)
#define mputs(s) fputs( s , stdout)
#define puti(i) printf("%d", i)

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
