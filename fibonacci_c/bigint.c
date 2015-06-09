//
//  bigint.c
//  fibonacci_c
//
//  Created by Don Reilly on 6/8/15.
//  Copyright (c) 2015 Don Reilly. All rights reserved.
//

#include "bigint.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define SHIFT   120
#define BASE    ((digit)1 << SHIFT)
#define MASK    ((digit)(BASE - 1))

bigint * new_bigint(size_t n) {
    bigint *x;
    x = malloc(sizeof(bigint) + n * sizeof(digit));
    assert(x != NULL);
    
    x->numDigits = n;
    return x;
}

bigint * add(bigint *a, bigint *b) {
    bigint *z;
    
    size_t i;
    digit carry = 0;
    
    if (a->numDigits < b->numDigits) {
        bigint *temp = a; a = b; b = temp;
    }
   
    z = new_bigint(a->numDigits + 1);
    if (z == NULL) return NULL;

    for (i = 0; i < b->numDigits; i++) {
        carry += a->digits[i] + b->digits[i];
        z->digits[i] = carry & MASK;
        carry >>= SHIFT;
    }
    for (; i < a->numDigits; i++) {
        carry += a->digits[i];
        z->digits[i] = carry & MASK;
        carry >>= SHIFT;
    }
    z->digits[i] = carry;
    
    return normalize(z);
}

bigint * normalize(bigint *n) {
    size_t j = n->numDigits;
    size_t i = j;
    while ( i > 0 && n->digits[i-1] == 0) --i;
    if (i != j) {
        n->numDigits = i;
        n = realloc(n, (sizeof(bigint) + i * sizeof(digit)));
    }
    return n;
}

void print(bigint *n) {
    int i, j, k, *d;
    k = (int) floor(36.12359947967774 * n->numDigits) + 1;
    d = calloc(k, sizeof(int));
    memset(d, 0, sizeof(int) * k);
    
    for(int l = (int)n->numDigits - 1; l > -1; l--)
    {
        if (l == 0)
        {
            for (i = 119; i > -1; i--)
            {
                if ((n->digits[l] >> i) & 1) d[0]++;
                if (i > 0) for (j = 0; j < k; j++) d[j] *= 2;
                for (j = 0; j < (k-1); j++) d[j+1] += d[j]/10, d[j] %= 10;
            }
        }
        else
        {
            for (i = 119; i > -1; i--)
            {
                if ((n->digits[l] >> i) & 1) d[0]++;
                for (j = 0; j < k; j++) d[j] *= 2;
                for (j = 0; j < (k - 1); j++) d[j+1] += d[j]/10, d[j] %= 10;
            }
        }
    }
    
    for (i = (k - 1); i > 0; i--) if (d[i] > 0) break;
    
    // Put characters into stream
    for(; i > -1; i--) putchar_unlocked('0'+d[i]);
    putchar_unlocked('\n');
    free(d);
    d = NULL;
    return;
}
