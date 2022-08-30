/**
 * @file sorting/c/quick_sort.h
 * @author TONBUL, Muhammet
 */

#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include "common.h"

static inline void
partition(Data __x[], int __l, int __r)
{
  int __lower = __l + 1, __upper = __r;
  
  swap(&__x[__l], &__x[(__l +__r) / 2]);

  Data __data = __x[__l];

  while (__lower <= __upper) {
    while (__data > __x[__lower])
      __lower++;
    while (__data < __x[__upper])
      __upper--;
    if (__lower < __upper)
      swap(&__x[__lower++], &__x[__upper--]);
    else
      __lower++;
  }

  swap(&__x[__upper], &__x[__l]);
  
  if (__l < __upper - 1)
    partition(__x, __l, __upper - 1);
  if (__upper + 1 < __r)
    partition(__x, __upper + 1, __r);
}

static inline void
quick_sort(Data __x[], int __n)
{
  if (__n < 2)
    return;
  
  int __i, __max;

  for (__i = 1, __max = 0; __i < __n; ++__i) {
    if (__x[__max] < __x[__i])
      __max = __i;
  }
  
  swap(&__x[__n - 1], &__x[__max]);
  
  partition(__x, 0, __n - 2);
}

#endif /* !__QUICK_SORT__ */