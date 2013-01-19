#include "../stdfuns.h"

double mmax(double a, double b) {
    return a > b ? a : b;
}

double pow4(double a) {
    return a*a;
}
#define tpow4(base) printf( #base  "^4 => %lf\n", pow4( base ))

double mpow(double a, double b) {
    double _ = a;
    if (b<0)
        for (; b<-1; a/=_,b++);
    else if (b==0)
        return 1;
    else
        for (; b>1; a*=_,b--);
    return a; 
}
#define tmpow(base, exp) printf( #base  "^" #exp "=> %lf\n", mpow( base , exp ))

double squares(double w, double h) {
    return w*h;
}
#define tsquare(w,h) printf( #w  " x " #h "=> %lf\n", squares(w,h))

int main(int argc, char** argv) {
    tsquare(1,     3   );
    tsquare(2,     2   );
    tsquare(3,     4.5 );
    tsquare(0.1,   2   );
    tsquare(0.001, 2   );
    tsquare(-0.1,  0.1 );
    tsquare(-3,    0.01);
    tsquare(-0.3,  2   );
    tsquare(-2,    3   );
    tsquare(2,     4   );
    return 0;
}

