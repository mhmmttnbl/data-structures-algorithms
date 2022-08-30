/**
 * @file sorting/c/common.h
 * @author TONBUL, Muhammet
 */

#ifndef __SORTING_COMMON__
#define __SORTING_COMMON__

#define __Size(__x) (sizeof(__x) / sizeof(__x[0]))

typedef int Data;

static inline void
swap(Data *__x, Data *__y)
{
  Data __t = *__x;
  
  *__x = *__y;
  *__y = __t;
}

static inline void
comp_swap(Data *__x, Data *__y)
{ if (*__y < *__x) swap(__x, __y); }

#endif /* !__SORTING_COMMON__ */