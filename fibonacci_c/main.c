//
//  main.c
//  fibonacci_c
//
//  Created by Don Reilly on 6/8/15.
//  Copyright (c) 2015 Don Reilly. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "bigint.h"
#define LIMIT   2000

void safe_free(void *n);

int main(int argc, const char * argv[]) {
    bigint *a;
    bigint *b;
    bigint *c;
    int d;
	
	digit m = 2000000;
	char BUFFER[m];
	//BUFFER = realloc(BUFFER, sizeof(out_arr));
	memset(BUFFER, '\0', sizeof(BUFFER));
	setvbuf(stdout, BUFFER, _IOFBF, m);
    
    a = new_bigint(1);
    b = new_bigint(1);
    d = LIMIT;
    
    a->digits[0] = 0;
    b->digits[0] = 1;
    
    d -= 2;
    //fprintf(stdout, "%d ", 0);
    print(a);
    //fprintf(stdout, "%d ", 1);
    print(b);
    c = add(a, b);
    
    while(d) {
        //fprintf(stdout, "%d ", LIMIT - d);
        print(c);
        free(a);
        a = b;
        b = c;
        c = add(a, b);
        d--;
    }
    
    //fprintf(stdout, "%d ", LIMIT - d);
	//fflush(stdout);
    print(c);
	fflush(stdout);
    free(a);
    free(b);
    free(c);
    return 0;
}
