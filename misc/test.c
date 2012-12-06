//
// Some C-lang tests.
//
// Author: Karolin Varner

#include <stdio.h>

int main() {
    printf("\n= Prefix/postfix =============================\n\n");

    int i = 23;
    printf("==> i: %i\n", i);
    printf("i-- => %i",   i--);
    printf("==> i: %i\n", i);
    printf("--i => %i", --i);
    printf("==> i: %i\n", i);
    printf("i++ => %i",   i++);
    printf("==> i: %i\n", i);
    printf("++i => %i", ++i);
    printf("==> i: %i\n", i);
    printf("i+=2 => %i",  i+=2);
    printf("==> i: %i\n", i);
    printf("i-=2 => %i",  i-=2);
    printf("==> i: %i\n", i);
    return 0;
}
