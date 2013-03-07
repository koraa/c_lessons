#include "../stdfuns.h"

/**
 * Find the maximum
 */
int ar_max(int *ar, size_t len) {
    int r = ar[0];
    for (size_t i=1; i<len; i++)
        if (ar[i] > r)
            r=ar[i];
    return r;
}

/**
 * Find the maximum and return its pos
 */
size_t ar_max_ps(int *ar, size_t len) {
    int r = ar[0];
    size_t p =0;
    for (size_t i=1; i<len; i++) {
        if (ar[i] > r) {
            r=ar[i];
            p=i;
        }
    }
    return p;
}

/**
 * Fill array with random number
 */
void ar_fill_rnd(int *ar, size_t len, int a, int z) {
    itr(i,len) {
        ar[i] = randrng(a,z);
    } 
}

/**
 * ALLOCATE MEMNORY
 * and the fill it with random numbers.
 * memory must be freed!
 */
int* PTR_CREATE_rnd(size_t len, int a, int z) {
    int* pt = (int*) malloc(len*sizeof(int));
    ar_fill_rnd(pt, len, a, z);
    return pt;
}

bool ar_contains(int *ar, size_t len, int x) {
    itr(i, len)
        if (ar[i] == x)
            return true;
    return false;
}

//===============================================
// Print

void dump_i_arr(int *a, size_t len) {
    size_t size = sizeof(int) * len;

    printf("int[] where: len=%ld, size=%ldbytes, max=%d@%ld: ", 
            len, size,
            ar_max(a,len), ar_max_ps(a,len));
    itr(i, len) {
        puti(a[i]);
        mputc(' '); 
    }

    printf("\n\t[REVERSE]: ");
    itr0(i, len) {
        puti(a[i]);
        mputc(' '); 
    }
    mputc('\n');
}

//=================================================
// TEST

void autoarr() {
    // (1) INIT
    int a[] = {-2, 4, 4, 122, 42};
    size_t len = sizeof(a) / sizeof(int);

    // PRINT
    dump_i_arr(a, len);

    // SET 42
    a[0] = a[1] = a[3] = 42;
    dump_i_arr(a, len);

    // GET d4
    int d4 = a[4];
    printf("d4 = a[4] = %i\n\n", d4);

    // LOTTO
    srand(time(NULL));

    puts("RANDOM 6!");
    size_t lotto_len = 6;
    int* lotto = PTR_CREATE_rnd(lotto_len,0,49);
    dump_i_arr(lotto, lotto_len);

    int guess;
    do {
        guess = randrng(0, 49);
        printf("\nGuess %i ->", guess);
    } while (! ar_contains(lotto, lotto_len, guess));
    puts("YESSS!");
    free(lotto);

}

void lotto() {
    // Real Lotto
    const size_t bot_l = 49;
    int bot[bot_l];
    itr(i, bot_l)
        bot[i] = i;

    const size_t d_l = 6;
    int d[d_l];
    
    size_t bot_use = bot_l;
    itr (no, d_l) {
       size_t p = randrng(0, 49-1-no);
       d[no] = bot[p];

        bot_use--;

       for (; p< bot_use; p++)
           bot[p] = bot[p+1];
    }
    puts("[REAL LOTTO]");
    dump_i_arr(d, d_l);
}

void userarr() {
    mgeti("Create array/len: ", len);

    int arr[len];
    itr(i, len) {
        printf("Create array/%d: ", i);
        scanf("%d", &arr[i]);
    }

    dump_i_arr(arr, len);
}

//==============================================
//RUN

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    autoarr();
    lotto();
    //userarr();
    return 0;
}
