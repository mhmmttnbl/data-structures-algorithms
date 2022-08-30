/**
 * @file sorting/c/insertion_sort.h
 * @author TONBUL, Muhammet
 */

#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__

#include "common.h"

static inline void
insertion_sort(Data __x[], int __n)
{
  for (int __i = 1, __j; __i < __n; ++__i) {
    Data __tmp = __x[__i];
    
    for (__j = __i; __j > 0 && __tmp < __x[__j - 1]; --__j)
      __x[__j] = __x[__j - 1];
    
    __x[__j] = __tmp;
  }
}

#endif /* !__INSERTION_SORT__ */