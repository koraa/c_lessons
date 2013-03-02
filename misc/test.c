//
// Some C-lang tests.
//
// Author: Karolin Varner

#include "../stdfuns.h"



test(prefix_vs_postfix) {
    int i = 23;
    printf("==> i: %i\n", i);
    printf("i-- => %i",   i--);
    printf("==> i: %i\n", i);
    printf("--i => %i", --i);
    printf("==> i: %i\n", i);
    printf("i++ => %i",   i++);
    printf("==> i: %i\n", i);
    printf("++i => %i", ++i);
    printf("==> i: %i\n", i);
    printf("i+=2 => %i",  i+=2);
    printf("==> i: %i\n", i);
    printf("i-=2 => %i",  i-=2);
    printf("==> i: %i\n", i);

    return true;
}

test(array_literal) {
    const size_t len = 5;
    int arr[] = {-3, 7, 5, 13, 42};

    printf("Array %p cont: ", arr);
    itr(i,len) {
        puti(arr[i]);
        mputc(' ');
    }
    mputc('\n');

    return true;
}

int main() {
    run(prefix_vs_postfix);
    run(array_literal);

    return 0;
}
