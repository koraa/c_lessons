/**
 * Run and compile:
 *
 *     gcc -o 1m1 *.c --std=gnu99 -O3 && ./1m1 20 20
 *
 * Challenge:
 *     Print a table where each position (x|y) is defined like:
 *
 *         {x*y | x=[1;9], y=[1,9]}
 *
 *  Author: Karolin Varner
 *  Date:   29.11.2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mputc(C) fputc( C , stdout)
#define mputs(s) fputs( s , stdout)
#define puti(i) printf("%d", i)

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

int main(int argc, char** argv) {
    int lx = atoi(argv[1]);
    int ly = atoi(argv[2]);

    size_t mxgap;
    free(itostr(ly*ly, &mxgap));
    mxgap+=2;

    for (int x = 1; x<=lx; x++) {
        for (int y = 1; y<=ly; y++) {
            size_t len;
            char* num = itostr(x*y, &len);
            fill(mxgap - len, ' ');
            mputs(num);
            free(num);
        }
        mputc('\n');
    }
    return 0;
}
