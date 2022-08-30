/**
 * @file sorting/c/bubble_sort.h
 * @author TONBUL, Muhammet
 */

#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__

#include "common.h"

static inline void
bubble_sort(Data __x[], int __n)
{
  for (int __i = 0; __i < __n - 1; ++__i) {
    for (int __j = __n - 1; __j > __i; --__j) {
      if (__x[__j] < __x[__j - 1])
        swap(&__x[__j], &__x[__j - 1]);
    } 
  }
}

#endif /* !__BUBBLE_SORT__ */