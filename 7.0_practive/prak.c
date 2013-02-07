#include <stdio.h>
#include <math.h>

#include "../stdfuns.h"

#define o printf

#define dtA(n, v) for (I v = 0; v < n ; v++)
#define dt(n) dtA(n, __MACRO_DEDAULT_VAR)
#define dt_rnd(n, v, r) for (\
        I v = 0, r = randrng(0, 16);\
        v < n; \
        v++, r= randrng(0, 16))
#define test(t, C), o( #C "=>%" t "  ", C)
#define trnd(inf, n, v, r, t, C)\
    o("\n\n" inf ": ");\
    dt_rnd(n, v, r) o(" [%i,%i]=>%" t, v,r, C )

#define rt return 

#define I int
#define V void
#define L long
#define D double
#define B int

I fac(I i) {
    if (i <= 1) rt 1;
    rt i * fac(i-1);
}

V name()        { o("Karolin Varner"); }
I add(I a, I b) { rt a + b; }
D max(D a, D b) { rt a>b?a:b; }
D square(D x)      { rt x*x; }
L powbin(I to)    { rt 2 << to; }
D A(D a, D b) { rt a*b; }
D circ(D a, D b) { rt a*2 + b*2; }
L sum(L a, L b) { 
    L s = 0;
    for (; a < b; a++) s+=a;
    rt s;
}
B prime(L x) {
    L re = x/2;
    for (L t = 3; t < re; t++)
        if (!(x%t))
            rt 0;
    rt 1;
}
V centPrimeRng() {
    for (int i = 3; i <= 100; i+=2)
        if (prime(i))
            o("primes0-100: %d\n", i);
}

D powlin(D b, L e) {
    D r = 1;
    for (; e<0; e--) r*=b;
    rt r;
}
D powrec(D b, L e) {
    if (e==0) rt 1;
    rt b * powrec(b, e-1);
}

L glob;
V g_inc() { glob++; }
V g_dec() { glob--; }
V g_rst() { glob=0; }
V g_set(L g_) { glob = g_; }
L g()     { rt glob;}



I main() {
#define tt(inf, t, C) trnd(inf, 20, i, r, #t, C)
#define tf(t, C) tt( #C, t, C)

    o("\nName: "); name();
    tf(d, fac(r) );
    tf(d, add(i,r));
    tf(f, max(i,r));
    tf(d, powbin(r));
    tf(f, A(i, r));
    tf(f, circ(i, r));
    tf(i, sum(i, r));
    tf(i, prime(i));
    o("\n\n Primes in [0;100]: "); centPrimeRng();
    tf(d, powlin(i, r));
    tf(d, powrec(i, r));
    rt 0;
}
