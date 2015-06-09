//
//  main.c
//  fibonacci_c
//
//  Created by Don Reilly on 6/8/15.
//  Copyright (c) 2015 Don Reilly. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "bigint.h"
#define LIMIT   50000

void safe_free(void *n);

int main(int argc, const char * argv[]) {
    bigint *a;
    bigint *b;
    bigint *c;
    int d;
    
    a = new_bigint(1);
    b = new_bigint(1);
    d = LIMIT;
    
    a->digits[0] = 0;
    b->digits[0] = 1;
    
    d -= 2;
    //printf("%d ", 0);
    //print(a);
    //printf("%d ", 1);
    //print(b);
    c = add(a, b);
    
    while(d) {
        //printf("%d ", LIMIT - d);
        //print(c);
        free(a);
        a = b;
        b = c;
        c = add(a, b);
        d--;
    }
    
    //printf("%d ", LIMIT - d);
    print(c);
    free(a);
    free(b);
    free(c);
    return 0;
}
