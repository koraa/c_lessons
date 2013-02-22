// prepend line nos

#include "../stdfuns.h"

int __TO_CASE_DIFF = ('A'-'a');

char to_upper_case(char c) {
    if (islower(c))
        return c + __TO_CASE_DIFF;
    return c;
}

char to_lower_case(char c) {
     if (isupper(c)) 
         return c - __TO_CASE_DIFF;
     return c;

}

int main() {
    char c;
    while ((c = getchar()) != EOF) {
       putchar(to_upper_case(c));
    }
    return 0;
}
