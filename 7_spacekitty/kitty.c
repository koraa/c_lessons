// cat while counting spaces

#include "../stdfuns.h"

int main() {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            i++;
        putc(c, stdout);
    }
    printf("==> %i spaces\n", i);
    return 0;
}
