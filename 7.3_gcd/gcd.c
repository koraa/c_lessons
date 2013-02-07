// Greatest common divisor
#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b) {
    if (a>b)
        return gcd(a-b,b);
    else if (a<b)
        return gcd(a,b-a);
    else
        return a;
}

int main(int argc, char** argv) {
    long a = atol(argv[1]), b = atol(argv[2]);
    printf("%li\n", gcd(a,b));
}
