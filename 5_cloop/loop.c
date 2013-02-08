#include <stdio.h>

#define true 1
#define false 0
#define loop while(true)

void main() {
    for (char c = -127; c>-128; c++)
        printf("%c | %d | 0x%x\n", c,c,c);
}
