#include <stdio.h>

#define true 1
#define false 0
#define loop while(true)

void main() {
    double acc = 0, in;
    do {
        printf("+> ");
        scanf("%lf", &in);
        acc += in;
        printf("==> %lf\n", acc);
    } while (in != 0.0);
}
