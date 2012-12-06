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
    int base = atol(argv[1]);
    int no   = atol(argv[2]);

    for (int lno = 0; lno<=no; lno++) {
        printf("%i", base);
        int i, pr;
        for (i = 0, pr = base; i<lno; i++, pr*=base)
            printf(" * %i", base);
        printf(" = %i\n", pr);
    }
    return 0;
}
