// prepend line nos

#include "../stdfuns.h"

int main() {
    char c;
    int i = 0;
    
    printf("%i\t| ", i++);
    while ((c = getchar()) != EOF) {
       putchar(c);
       if (c == '\n')
           printf("%i\t| ", i++);

    }
    return 0;
}
