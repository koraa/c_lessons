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

void quicksort(int* ar, size_t len) {
    // Vars ------------------------------------------------

    size_t j, i = len-1; // Two indices
    int mean = 0, t;     // Avrage, swap-temp
    bool sorted = true;  // Flag

    // Special case: 2 elements ---------------------------

    if (len<3) {
        if (ar[0] > ar[1]) {
            t = ar[0];
            ar[0] = ar[1];
            ar[1] = t;
        }
    }

    // Mean/Check ------------------------------------------

    // Compute mean value
    // Check if the array is sorted
    for (; i>0; i--) { j=i-1;
        mean+=ar[i];

        if (ar[i] > ar[j]) // Check if it is NOT sorted
            sorted=false;
    }
    mean+=ar[0];
    mean/=len;

    // Special case: Allready sorted -----------------------
    
    // Dont continue if we are allready sorted
    if (sorted)
       return;
    
    // Actually sort ----------------------------------------
    
    for(;;) {
        //i: Find the first elem < mean
        //j: Find the last (reverse first) elem > mean
        for (i=0;     i<len && ar[i]<mean; i++); 
        for (j=len-1; j>=0  && ar[j]>mean; j--); 
        
        printf("%i@%li < %i@%li | mean=%i --> ", ar[i], i, ar[j], j, mean);
        if (i<j) { // Not completely sorted ==> swap
            printf("SWAP!\n");
            t = ar[i];
            ar[i] = ar[j];
            ar[j] = t; 
        } else  // The buckets seem to be ordered + we are at the border
            break;
    }

    // And now recurse: create subbuckets (i+j are at the border)
    if (i>0) {
        printf("RECURSE! split=%li\n", i);
        quicksort(ar+i, len-i);
        quicksort(ar, i);
    }
}

///////////////////////////////////////////////
// Main

#define sortt_lr(f, a, z, len) {      \
    mputs("\n= " #f ":\n");           \
                                      \
    size_t ar_l = len;                \
    int* ar = randarng(a, z, ar_l);   \
    dump_i_arr(ar,ar_l, false);       \
    f(ar, ar_l);                      \
    dump_i_arr(ar, ar_l, false);      \
}

#define sortt_l(f, len) sortt_lr(f, 0, len*2, len)

#define sortt(f) sortt_l(f, 16)

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    rndinit();

    sortt(bubblesort);
    sortt(quicksort);
}
