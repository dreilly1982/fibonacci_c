//
//  bigint.h
//  fibonacci_c
//
//  Created by Don Reilly on 6/8/15.
//  Copyright (c) 2015 Don Reilly. All rights reserved.
//

#ifndef __fibonacci_c__bigint__
#define __fibonacci_c__bigint__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef __uint128_t digit;
typedef struct bigint {
    size_t numDigits;
    digit digits[];
} bigint;

bigint * new_bigint(size_t n);
bigint * add(bigint *a, bigint *b);
bigint * normalize(bigint *n);
void print(bigint *n);

#endif /* defined(__fibonacci_c__bigint__) */
