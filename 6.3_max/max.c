#include "../stdfuns.h"

double mmax(double a, double b) {
    return a > b ? a : b;
}

double pow4(double a) {
    return a*a;
}
#define tpow4(base) printf( #base  "^4 => %lf\n", pow4( base ))

double mpow(double a, double b) {
    b--;
    for (double _ = a; b>0; a*=_,b--);
    return a; 
}
#define tmpow(base, exp) printf( #base  "^" #exp "=> %lf\n", mpow( base , exp ))

int main(int argc, char** argv) {
    tmpow(2,3);
    tmpow(2,4);
    tmpow(3,3);
    return 1;
}

