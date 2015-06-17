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
#define LIMIT   2000

void safe_free(void *n);

int main(int argc, const char * argv[]) {
    bigint *a;
    bigint *b;
    bigint *c;
	char *buffer;
    int d;
    
    a = new_bigint(1);
    b = new_bigint(1);
    d = LIMIT;
    
    a->digits[0] = 0;
    b->digits[0] = 1;
    
    d -= 2;
	buffer = print(a);
	printf("%d %s\n", 0, buffer);
	free(buffer);
	buffer = NULL;
	buffer = print(b);
    printf("%d %s\n", 1, buffer);
	free(buffer);
	buffer = NULL;
    c = add(a, b);
    
    while(d) {
		buffer = print(c);
        printf("%d %s\n", LIMIT - d, buffer);
        free(buffer);
		buffer = NULL;
        free(a);
        a = b;
        b = c;
        c = add(a, b);
        d--;
    }
    
	buffer = print(c);
    printf("%d %s\n", LIMIT - d, buffer);
    free(buffer);
	buffer = NULL;
    free(a);
    free(b);
    free(c);
    return 0;
}
