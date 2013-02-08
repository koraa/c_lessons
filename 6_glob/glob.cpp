#include <stdio.h>

int glob = 0;

void inc() {glob++;}
void dec() {glob--;}
void rset() {glob=0;}
void set(int i) {glob=i;}
int  get() {return glob;}
void ptrt() {printf("GLOB=%i\n",get());}

int main() {
    ptrt();
    {}
inc(); ptrt();
    dec(); ptrt();
    set(42); ptrt();
    rset(); ptrt();
     
    return 0;
}
