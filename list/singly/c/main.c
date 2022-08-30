/**
 * @file list/singly/c/main.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>

#include "list.h"

static void 
display(Data __x)
{ printf("Element-> %d\n", __x); }

int
main(int argc, char **argv)
{
  /* Initialize the list */
  struct List *__list = List_init();

  /* Push back */
  __list->push_back(__list, 0);
  __list->push_back(__list, 1);
  __list->push_back(__list, 2);
  __list->push_back(__list, 3);
  __list->push_back(__list, 4);

  /* Push front */
  __list->push_front(__list, 9);
  __list->push_front(__list, 8);
  __list->push_front(__list, 7);
  __list->push_front(__list, 6);
  __list->push_front(__list, 5);
  
  /* Fetch first element */
  printf("First element : %d\n", __list->front(__list));
  /* Fetch last element */
  printf("Last element : %d\n", __list->back(__list));

  /* Traverse over the list */
  __list->traverse(__list, display);

  /* Remove from the end of the list */
  __list->pop_back(__list);
  __list->pop_back(__list);

  printf("After pop_back...\n");
  /* Traverse over the list after removing from end */
  __list->traverse(__list, display);

  /* Remove from the begining of the list */
  __list->pop_front(__list);
  __list->pop_front(__list);

  printf("After pop_front...\n");
 
  /* Traverse over the list after removing from begining */
  __list->traverse(__list, display);

  return(0);
}