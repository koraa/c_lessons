#include <stdio.h>

typedef unsigned long long lnum;

lnum fac(lnum n) {
    if (n == 0)
        return 1;
    else if (n>0)
        return fac(n-1)*n;
    else
        return -1;
}

void main() {
    lnum i;
    for (;;) {
        printf("fac pleaz! ");
        scanf("%lli", &i);
        printf("===> %lli\n", fac(i));
    }
}
