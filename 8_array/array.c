#include "../stdfuns.h"

void dump_i_arr(int[] i)
    size_t size = sizeof(i);
    size_t len  = (size / sizeof(int));

    printf("int[] where: len=%d, size=%dbytes: ", len, size);
    
    itr(i, len) {
        puti(a[i]):
        mputc(' '); 
    }
    mputc('\n');
}

void autoarr() {
    int a[] = {-2, 4, 4, 122, 42};
    const size_t len = (sizeof(a) / sizeof(int));

}

int main() {
    return 0;
}
