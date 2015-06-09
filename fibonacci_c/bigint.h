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

#ifdef __SIZEOF_INT128__
typedef __uint128_t digit;
#define BASE10PERDIGIT	36.12359947967774
#define SHIFT	120
#elif defined(__UINT64_TYPE__)
typedef uint64_t digit;
#define BASE10PERDIGIT	18.06179973983887
#define SHIFT	60
#else
typedef uint32_t digit;
#define BASE10PERDIGIT	9.030899869919436
#define SHIFT	30
#endif

typedef struct bigint {
    size_t numDigits;
    digit digits[];
} bigint;

bigint * new_bigint(size_t n);
bigint * add(bigint *a, bigint *b);
bigint * normalize(bigint *n);
void print(bigint *n);

#endif /* defined(__fibonacci_c__bigint__) */
