#include <iostream>
#include <cmath>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>

#include "boolarr.h"

using namespace std;

typedef unsigned long ulong;
typedef unsigned int  uint;

std::vector<ulong> primes;
bool ckprime(ulong mayprime) {
    double frt = std::sqrt(mayprime);
    ulong rt = (ulong)frt;

    // Test if sqrt is integer
    if (frt == rt)
        return false;

    // Exclued all other primes
    // Requires primes to contain all primes < mayprime
    ulong div; uint idx; uint sz=primes.size();
    for (idx=0; idx<sz; idx++) {
        div = primes[idx];

        // Break on sqrt(rt)
        if (div >= rt)
            return true;

        if (mayprime % div == 0)
            return false;
    }

    return true;
}

inline double secs() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec + tv.tv_usec*1E-6;
}

int main() {
    bool ar[2048];
    BoolArr clz (2048);

    for (int i = 0; i < 2048; i++) {
        bool b = rand() > RAND_MAX/2;
        ar[i] = b;
        clz.set(i, b);
    }

    for (int i = 0; i < 2048; i++) {
        bool b0 = ar[i], b1 = clz.get(i);
        cout << i << " | " << b0 << " == " << b1 << " ==> " << b0 == b1 << '\n';
        if (b0 != b1) {
            cout << "FAIL after " << i << '\n';
            return 1;
        }
    }
    cout << "SUCCESS!\n";
    exit(0);

    int cntdown = 1E6;
    double t0 = secs();

    for (ulong i = 1;i<(int)3E7;i+=2) {
        if (ckprime(i))
            primes.push_back(i);

        // UI Messages
        if (i % cntdown < 3) {
            double found = primes.size(), tested=i, T=(secs()-t0), speed=found/T;

            cout.unsetf( cout.scientific); cout.setf( cout.fixed);
            cout << "After " << T << "s --> " << speed << " primes/sec | ";
            
            cout.unsetf( cout.fixed); cout.setf( cout.scientific);
            cout << "tested/found <=> " << found << "  /  " << tested << "  ===>  " <<  found/tested << '\n';
        }
    }
    cout.unsetf( cout.scientific); cout.setf( cout.fixed);
    cout << "Done after " << (secs()-t0) << "s\n";

    return 0;
}
