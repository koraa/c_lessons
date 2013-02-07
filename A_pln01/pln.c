#include <stdio.h>

int main(void) {

    return 0;
}

double min(double a, double b, double c, double d) {
    a=a<b?a:b;
    a=a<c?a:c;
    return a<d?a:dM
}

double mean(double a, double b, double c) {
    return (a+b+c)/3;
}

void ptasciirng(int a, int z) {
    if (a>z) {
        int t = a;
        a=z;
        z=t;
    }
    if (a<0||b>127) {
        printf("Bad arg! Range is [%i;%i] but must be within [0;127]", a,z);
        return;
    }
    for (;a<=z;a++)
        printf("%i -> %c", a,a);
}

int durToS(int h, int m, int s) {
    return (h*60 + m) * 60 + s;
}
