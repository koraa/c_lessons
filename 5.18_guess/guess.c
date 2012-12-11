#include "../stdfuns.h"

static int tryout = 9;

int main(int argc, char** argv) {
    srand(time(NULL));
    int rnd = randrng(0,1000000000);

    loopn(i) {
        mgeti("Guess> ", inp);

        if (inp == rnd) {
            printf("Correct, %ind try!", i+1);
            return 0;
        }

        printf("Nop. Too %s.\n", inp>rnd ? "big" : "small");
    }
    return 1;
}

