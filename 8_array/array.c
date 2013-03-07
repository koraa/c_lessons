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
    return r;
}

//===============================================
// Print

void dump_i_arr(int *a, size_t len) {
    size_t size = sizeof(int) * len;

    printf("int[] where: len=%ld, size=%ldbytes: ", len, size);
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
    //userarr();
    return 0;
}
