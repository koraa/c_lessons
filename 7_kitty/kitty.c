#include "../stdfuns.h"

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putc(c, stdout);
    }
    return 0;
}
