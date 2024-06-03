#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Limits of various data types in C:\n\n");

    printf("char:\n");
    printf("  CHAR_MIN  : %d\n", CHAR_MIN);
    printf("  CHAR_MAX  : %d\n", CHAR_MAX);
    printf("  SCHAR_MIN : %d\n", SCHAR_MIN);
    printf("  SCHAR_MAX : %d\n", SCHAR_MAX);
    printf("  UCHAR_MAX : %u\n", UCHAR_MAX);

    printf("\nshort int:\n");
    printf("  SHRT_MIN  : %d\n", SHRT_MIN);
    printf("  SHRT_MAX  : %d\n", SHRT_MAX);
    printf("  USHRT_MAX : %u\n", USHRT_MAX);

    printf("\nint:\n");
    printf("  INT_MIN   : %d\n", INT_MIN);
    printf("  INT_MAX   : %d\n", INT_MAX);
    printf("  UINT_MAX  : %u\n", UINT_MAX);

    printf("\nlong int:\n");
    printf("  LONG_MIN  : %ld\n", LONG_MIN);
    printf("  LONG_MAX  : %ld\n", LONG_MAX);
    printf("  ULONG_MAX : %lu\n", ULONG_MAX);

    printf("\nlong long int:\n");
    printf("  LLONG_MIN : %lld\n", LLONG_MIN);
    printf("  LLONG_MAX : %lld\n", LLONG_MAX);
    printf("  ULLONG_MAX: %llu\n", ULLONG_MAX);

    printf("\nfloat:\n");
    printf("  FLT_RADIX     : %d\n", FLT_RADIX);
    printf("  FLT_MANT_DIG  : %d\n", FLT_MANT_DIG);
    printf("  FLT_DIG       : %d\n", FLT_DIG);
    printf("  FLT_MIN_EXP   : %d\n", FLT_MIN_EXP);
    printf("  FLT_MAX_EXP   : %d\n", FLT_MAX_EXP);
    printf("  FLT_MIN       : %e\n", FLT_MIN);
    printf("  FLT_MAX       : %e\n", FLT_MAX);
    printf("  FLT_EPSILON   : %e\n", FLT_EPSILON);

    printf("\ndouble:\n");
    printf("  DBL_MANT_DIG  : %d\n", DBL_MANT_DIG);
    printf("  DBL_DIG       : %d\n", DBL_DIG);
    printf("  DBL_MIN_EXP   : %d\n", DBL_MIN_EXP);
    printf("  DBL_MAX_EXP   : %d\n", DBL_MAX_EXP);
    printf("  DBL_MIN       : %e\n", DBL_MIN);
    printf("  DBL_MAX       : %e\n", DBL_MAX);
    printf("  DBL_EPSILON   : %e\n", DBL_EPSILON);

    printf("\nlong double:\n");
    printf("  LDBL_MANT_DIG : %d\n", LDBL_MANT_DIG);
    printf("  LDBL_DIG      : %d\n", LDBL_DIG);
    printf("  LDBL_MIN_EXP  : %d\n", LDBL_MIN_EXP);
    printf("  LDBL_MAX_EXP  : %d\n", LDBL_MAX_EXP);
    printf("  LDBL_MIN      : %Le\n", LDBL_MIN);
    printf("  LDBL_MAX      : %Le\n", LDBL_MAX);
    printf("  LDBL_EPSILON  : %Le\n", LDBL_EPSILON);

    return 0;
}

