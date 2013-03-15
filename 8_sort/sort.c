#include "../stdfuns.h"

/////////////////////////////////////////////
// Algorythims

void bubblesort(int* ar, size_t len) {
    int t, run;
    size_t j, i;

    do {
        run=false;
        i=len-1;

        for (; i>0; i--) { j=i-1;
            if (ar[i] < ar[j]) {
                t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;

                run=true;
            }
        }
    } while (run);
}

///////////////////////////////////////////////
// Main

#define sortt_l(f, len)        \
    size_t ar_l = len;      \
    int* ar = randar(ar_l); \
    dump_i_arr(ar,ar_l);    \
    f(ar, ar_l);   \
    dump_i_arr(ar, ar_l);

#define sortt(f) sortt_l(f, 16)

int main() {
    sortt(bubblesort);
}
