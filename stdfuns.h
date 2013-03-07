/**
 * Frequently needet standart definitions.
 *
 * Author: Karolin Varner
 * Date:   6.12.2012
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


/////////////////////////
// LOOP WRAPPERS

#define loop for(;;)
#define loopn(v) for(size_t v=0;;v++)
// DEPRECATE
#define loopi(v,m) for(size_t v=0; v < m ; v++ )

#define itr(v, mx) loopi(v, mx)
#define itr0(v, mx) for (size_t v=mx-1; v=>0; v--)

///////////////////////////
// IO

/** Short char write  to stdout*/
#define mputc(C) fputc( C , stdout)
/** Short string write to stdout */
#define mputs(s) fputs( s , stdout)
/** Short write decimal integer to stdout */
#define puti(i) printf("%d", i)
/** Write int followed by \n to stout */
#define putiln(i) printf("%d\n", i)
/** Read decimal int with prompt */
#define mgeti(s, v) int v; mputs( s ); scanf("%d", &v)

//////////////////////////
// BOOLS

typedef int bool;

#define false 0
#define true  1

/////////////////////////
// Testing

bool test_result = true;
int  test_sum_success = 0;
int test_sum_failure = 0;

#define test(name) bool test_ ## name()
#define run(name)                                              \
    printf("===============================================\n" \
           "= " #name "\n\n");                                 \
    printf("\n\nTEST: " #name "\n    =>%s!\n\n",               \
           ( test_result = test_ ## name() ) ?                 \
                "SUCCEEDED" : "FAILED");                       \
    if (test_result) test_sum_success++;                       \
    else             test_sum_failure;

///////////////////////////
// STDIO UTILS

#define STR_IMAXLEN 50

// DEPRECATE
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
