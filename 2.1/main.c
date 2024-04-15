#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
    // Direct computation for signed integer types
    int smin_int = INT_MIN;
    int smax_int = INT_MAX;

    short smin_short = SHRT_MIN;
    short smax_short = SHRT_MAX;

    long smin_long = LONG_MIN;
    long smax_long = LONG_MAX;

    char smin_char = CHAR_MIN;
    char smax_char = CHAR_MAX;

    // Direct computation for unsigned integer types
    unsigned int umin_int = 0;
    unsigned int umax_int = UINT_MAX;

    unsigned short umin_short = 0;
    unsigned short umax_short = USHRT_MAX;

    unsigned long umin_long = 0;
    unsigned long umax_long = ULONG_MAX;

    unsigned char umin_char = 0;
    unsigned char umax_char = UCHAR_MAX;

    float smin_float = FLT_MIN;
    float smax_float = FLT_MAX;

    double smin_double = DBL_MIN;
    double smax_double = DBL_MAX;

    long double smin_ldouble = LDBL_MIN;
    long double smax_ldouble = LDBL_MAX;

    printf("umin_int: %u, umax_int: %u\n", umin_int, umax_int);
    printf("umin_short: %hu, umax_short: %hu\n", umin_short, umax_short);
    printf("umin_long: %lu, umax_long: %lu\n", umin_long, umax_long);
    printf("umin_char: %u, umax_char: %u\n", umin_char, umax_char);
    printf("smin_int: %d, smax_int: %d\n", smin_int, smax_int);
    printf("smin_short: %hd, smax_short: %hd\n", smin_short, smax_short);
    printf("smin_long: %ld, smax_long: %ld\n", smin_long, smax_long);
    printf("smin_char: %d, smax_char: %d\n", smin_char, smax_char);
    printf("smin_float: %f, smax_float: %f\n", smin_float, smax_float);
    printf("smin_double: %lf, smax_double: %lf\n", smin_double, smax_double);
    printf("smin_ldouble: %Lf, smax_ldouble: %Lf\n", smin_ldouble, smax_ldouble);
    return 0;
}