#include <stdint.h>
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#define F (1<<14)

/*  FixedPoint
    Represent Real Number with 17.14 fixed-point number representation
    ---   ---------------------------------   -----------------------
   | 1 | |           17 bits               | |        14 bits        |  = 32 bits of int as usual
    ---   ---------------------------------   -----------------------
    sign      represent the part before         represent the part
    bit             decimal point               after decimal point

    to comvert any number to fixed point number ==> real number << 14

    MAX VALUE = (2**31 - 1)/(2**14) = approx. 131,071.999. ==> all 17 bits are full (1111...)
*/
typedef int fixedpoint;

static inline fixedpoint convert_to_fixed_point(int n)
{
    return n * F;
}
/*
rounding toward zero
*/
static inline int convert_to_int(fixedpoint x)
{
    return x / F;
}
/*
rounding to nearest
*/
static inline int round_to_int(fixedpoint x)
{
    if(x >= 0){
        return (x + F / 2) / F ;
    }
    if(x <= 0)
        return (x - F / 2) / F;
}

static inline fixedpoint add_to_real(fixedpoint x, fixedpoint y)
{
    return x + y;
}

static inline fixedpoint subtract_real(fixedpoint x, fixedpoint y)
{
    return x - y;
}

static inline fixedpoint add_to_int(fixedpoint x, int n)
{
    return x + (n * F);
}
static inline fixedpoint subtract_int(fixedpoint x, int n)
{
    return x - (n * F);
}
static inline fixedpoint multiply_by_real(fixedpoint x, fixedpoint y)
{
    return ((int64_t)x) * y / F;
}
static inline fixedpoint divide_by_real(fixedpoint x, fixedpoint y)
{
    return ((int64_t)x) * F / y;
}
static inline fixedpoint multiply_by_int(fixedpoint x, int n)
{
    return x * n;
}
static inline fixedpoint divide_by_int(fixedpoint x, int n)
{
    return x / n;
}
#endif
