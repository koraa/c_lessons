#include "../stdfuns.h"

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

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    autoarr();
    userarr();
    return 0;
}
