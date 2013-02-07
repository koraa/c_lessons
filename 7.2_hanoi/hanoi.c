#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef long long int hnum;
typedef char* cstring;


/**
 * Datastructure for a single tower of hanoi.
 * Holds a list of discs represented by their radius,
 * their capacity and their number of elements.
 */
struct htower_ {
    hnum *stack;
    hnum top, cap;
    cstring name;
};
typedef struct htower_ htower;

/////////////////////////////////////////////////////////
// DEBUG

void pt_tower(htower* ht) {
    printf("Tower: %s\n\ttop=%li\n\tcap=%li\n\tStack: ",
            ht->name, ht->top, ht->cap ); 

    hnum* stack = ht->stack;
    for (int i = 0; i < ht->cap; i++) {
        printf("%li ", stack[i]);
    }
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////
// Data/Types

/** Make a new htower with the given capacity and no elements. */
void ht_init(htower* t, hnum cap, cstring name) {
    t->top = -1;
    t->cap = cap;
    t->name = name;
    t->stack = malloc( cap * sizeof(hnum));
}

/** 
 * Safely add an element to the tower
 * (by safely i mean EXIT(23) with an error message).
 */
void ht_push(htower* t, hnum r) {
    hnum ntop = t->top+1;

    if (t->cap <= ntop) {
        fprintf(stderr, 
                "[FATAL] Error trying to add a %lind element"
                 "to tower %s with a capacity of %li\n",
                 ntop, t->name, t->cap);
        pt_tower(t);
        exit(23);
    }

    if (t->top > -1) {
        hnum toprad = t->stack[t->top];
        if (r > toprad) {
            fprintf(stderr, "[FATAL] Error trying on %s to add a"
                    "%lind element(r=%li) to smaller element(r=%li).\n",
                    t->name, ntop, r, toprad);
            pt_tower(t);
            exit(23);
        }
    }
    t->top = ntop;
    t->stack[ntop] = r;
}

/** 
 * Safely pop an element from an tower.
 * (by safely i mean EXIT(23) with an error message).
 *
 * Return:
 *  The rad of that element.
 */
hnum ht_pop(htower* t) {
   if (t->top < 0) {
        fprintf(stderr, 
            "[FATAL] Error trying to pop element from empty tower %s\n", t->name);
        pt_tower(t);
        exit(23);
   }
   return t->stack[t->top--];
}

/**
 * Create a set of 3 htowers called "A","B","C",
 * where a holds the given number of elements.
 */
htower* ts_init(hnum h) {
    htower* set = malloc(3*sizeof(htower));
    ht_init(set,   h+1, "A");
    ht_init(set+1, h+1, "B");
    ht_init(set+2, h+1, "C");

    for (;h > 0; h--) {
        ht_push(set, h);
    }

    return set;
}

///////////////////////////////////////////////////////
// Render

/** Compute the width of a tower */
hnum trad(htower* ht) {
    if (ht->top < 0) return 0;
    return ht->stack[0];
}

int hexlen(int i) {
    if (i == 0) return 1;

    int r = 0;
    for (; i>0; i/=16)
        r++;
    return r;
}

char space = ' ',
     wood = '|',
     bord = '#',
     disk = '=',
     disk_sub = '.',
     disk_add = 'O',
     ground = '-';
int Hpad = 2, Vpad = 1;

/** Print a single char to stdout */
 void mputc(char c) { fputc(c, stdout); }

/** Print the given char n times */
 void fill(char c, int n) {
    for(;n>0;n--)
        mputc(c);
}

/** Print a carriage return. */
 void cr() { mputc('\n'); }

/** fill, then cr() */
 void lfill(char c, int n) {
   fill(c,n);
   cr(); 
}

/**
 * Render a towerset to stdout.
 *
 * Args:
 *     - ht: The Towerset to render
 *     - N:  The number of towers
 */
void render(htower* ht, hnum N) {
    hnum ht_mxrad = 0;
    hnum ht_h = (ht +0 )->cap;

    for (hnum i=0; i<N; i++) {
        hnum w = trad(ht+i);
        if (w>ht_mxrad)
            ht_mxrad = w;
    }
    hnum ht_w = ht_mxrad*2 +1;
    hnum insidew = (ht_w + Hpad)*3;
    // Account for padding | border | padding | ... | border
    hnum width = insidew + Hpad + 1 + Hpad + 1; 

    // UPPER BORDER
    lfill(bord, width);

    // Vpad LINE FREE
    for (int i = Vpad; i>0; i--) {
        mputc(bord); fill(space, width-2); mputc(bord);  
        cr();
    }

    // TOWERS
    for (int l=ht_h-1; l >= 0; l--) {
        mputc(bord);
        fill(space, Hpad);

        for (int t=0; t<N;t++) {
            int rad = 0;
            if ((ht + t)->top >= l)
                rad = (ht + t)->stack[l];
            int airrad = ht_mxrad-rad;

            fill(space, airrad);
            fill(disk, rad);

            if (rad <= 0)
                mputc(wood);
            else
                printf("%x", rad);

            fill(disk, rad-hexlen(rad)+1);
            fill(space, airrad);

            fill(space, Hpad);
        }

        fill(space, Hpad);
        mputc(bord);

        cr();
    }


    // BOTTOM
    mputc(bord);
    fill(space,Hpad);
    fill(ground, insidew);
    fill(space, Hpad);
    mputc(bord);
    cr();


    // Vpad LINE FREE
    for (int i = Vpad; i>0; i--) {
        mputc(bord);
        fill(space, width-2); 
        mputc(bord);
        cr();
    }

    // LOWER BORDER
    lfill(bord, width);
    cr();
}

//////////////////////////////////////////////////////////////////////////////
// Controller
//

/**
 * Imagine the towers of hanoi;
 *
 * Move n elems (top to bottom) from pos p0 to pZ wile using pstack as a stack.
 * This function assumes that:
 * - The elements on p0 are stacked
 *   so that the higher elements are smaller than the lower ones
 * - Neither on pstack nor pZ is an element smaller than p0[top]
 *
 * The result is streamed out as instructions on stdout.
 *
 * Return:
 *     The value of th counter
 */
hnum movhanoi(hnum n, htower* data, hnum p0, hnum pstack, hnum pZ, hnum cnt) {
    if (n < 1) return cnt;

    cnt = movhanoi(n-1, data, p0, pZ, pstack, cnt);
    
    printf("%i | mov %i : %i -> %i\n", cnt++, n, p0, pZ);

    hnum disc = ht_pop(data+p0);
    ht_push(data+pZ, disc);
    render(data, 3);
    sleep(1);

    return movhanoi(n-1, data, pstack, p0, pZ, cnt);
}

int main() {
    int N = 24;

    htower* ts = ts_init(N);
    render(ts,3);

    movhanoi(N, ts, 0, 1, 2, 0);
    return 0;
}
