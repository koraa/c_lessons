#include <stdio.h>

#define POW(a) (a) * (a)
long pow(long a) {return a*a;}
#define TPOW(a) printf("pow %i = %i = %i\n", a, POW(a), pow(a))

int main() {
    TPOW(13);
    TPOW(15);
    TPOW(17);

    return 0;
}
