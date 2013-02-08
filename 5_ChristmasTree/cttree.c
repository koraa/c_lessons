#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char** argv) {
    int tr_h  = 8,
        tr_ex = 1,
        st_h  = 3,
        st_w  = 2,
        tr_g  = 1,
        st_g  = 1,
        zk_n  = 3,
        zk_w  = 1;
    char tr_c  = '*',
         st_c  = 'I';
    for (int ano = 1; ano < argc; ano++) {
        char* arg = argv[ano];
        if (arg[0] != '-') {
            printf("Bad Param: %s", arg);
            return 1;
        }

        char C = arg[1];
        if (C == '\0') {
            printf("Bad Param: %s", arg);
            break;
        }

        char* val = arg+2;
        switch(C) {
            case 'h':
                tr_h = atoi(val);
                break;
            case 'e':
                tr_ex = atoi(val);
                break;
            case 'H':
                st_h = atoi(val);
                break; 
            case 'W':
                st_w = atoi(val);
                break;
            case 'L':
                tr_c = val[0];
                break;
            case 'S':
                st_c = val[0];
                break;
            case 'g':
                tr_g = atoi(val)+1;
                break;
            case 'G':
                st_g = atoi(val)+1;
                break;
            case 'z':
                zk_n = atoi(val);
                break;
            case 'Z':
                zk_w = atoi(val);
                break;
        }
    }

    int spaceno=tr_h*tr_ex;
    int initleaves = st_w%2 ? 1 : 2;

    for (int l=0, zmod=false; l<=tr_h; l++) {
        int spno = spaceno-(l*tr_ex);
        int lno  = initleaves+(l*tr_ex*2);
        
        fill(spno, ' ');
        fill(lno,  tr_c);
        fill(tr_g, '\n');

        if ((l+1)%zk_n == 0) {
            if (zmod)
                zmod = false;
            else  {
                l-=zk_w;
                zmod = true;
            }
        }
    }

    spaceno-=st_w/2;
    spaceno+=initleaves-1; // Account for the movement of the tree if the with is even
    for (int l=0; l<st_h; l++) {
        fill(spaceno, ' ');
        fill(st_w, st_c);
        fill(st_g, '\n');
    }
}

