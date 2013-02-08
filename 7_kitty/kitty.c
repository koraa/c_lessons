#include "../stdfuns.h"

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == 'e' || c == 'i' || c == 'o' || c == 'u')
            c = 'a';
        putc(c, stdout);
    }
    return 0;
}
