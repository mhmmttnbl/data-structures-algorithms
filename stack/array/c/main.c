/**
 * @file stack/array/c/main.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>

#include "stack.h"

void display(int __x)
{ printf("Element-> %d\n", __x); }

int
main(int argc, char **argv)
{
  /* Initialize the stack */
  struct Stack *__stack = Stack_init(10);

  /* Push */
  __stack->push(__stack, 1);
  __stack->push(__stack, 2);
  __stack->push(__stack, 3);
  __stack->push(__stack, 4);
  __stack->push(__stack, 5);

  /* Fetch top the stack */
  printf("Top of the stack : %d\n", __stack->top(__stack));

  /* Traverse over the stack */
  __stack->traverse(__stack, display);

  /* Remove */
  __stack->pop(__stack);
  __stack->pop(__stack);

  printf("After pop...\n");

  /* Traverse over the stack */
  __stack->traverse(__stack, display);

  return(0);
}