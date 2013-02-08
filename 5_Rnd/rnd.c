#include "../stdfuns.h"

static int tryout = 3;
char* pass;

int main(int argc, char** argv) {

    srand(time(NULL));
    loopi(i,10) {
        putiln(randrng(0, 1000));
    }
    return 0;
}

