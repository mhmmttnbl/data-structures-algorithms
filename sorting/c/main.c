/**
 * @file sorting/c/main.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "quick_sort.h"

void
display(Data __x[], int __i)
{ printf("Element-%d -> %d\n", __i, __x[__i]); }

void
traverse(int __x[], int __size, void (*__cb)(Data __x[], int __i))
{
  for (int __i = 0; __i < __size; ++__i)
    __cb(__x, __i);
}

int
main(int argc, char **argv)
{
  /* Sample array */
  int __arr[] = {5, 7, 2, 3, 9, 8, 11, 4};

  /* Selection sort */
  selection_sort(__arr, __Size(__arr));

  /* Insertion sort */
  // insertion_sort(__arr, __Size(__arr));
  
  /* Bubble sort */
  // bubble_sort(__arr, __Size(__arr));
  
  /* Quick sort */
  // quick_sort(__arr, __Size(__arr));

  /* Traverse over the array */
  traverse(__arr, __Size(__arr), display);

  return(0);
}