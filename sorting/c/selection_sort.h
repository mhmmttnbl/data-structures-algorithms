/**
 * @file sorting/c/selection_sort.h
 * @author TONBUL, Muhammet
 */

#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__

#include "common.h"

static inline void
selection_sort(Data __x[], int __n)
{
  for (int __i = 0, __j, __l; __i < __n - 1; ++__i) {
    for (__j = __i + 1, __l = __i; __j < __n; ++__j) {
      if (__x[__j] < __x[__l])
        __l = __j;
    }
    swap(&__x[__l], &__x[__i]);
  }
}

#endif /* !__SELECTION_SORT__ */