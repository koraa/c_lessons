#include <stdio.h>

#define true 1
#define false 0
#define loop while(true)

void main() {
    int i = -220, min = 0, max = 9;
    
    do {
        printf("[%i] gimmeh a num:\n> ", i);
        scanf("%d", &i);
    } while (i < min || i > max);

    printf("YAYYYYOUT: %i\n", i);
}
