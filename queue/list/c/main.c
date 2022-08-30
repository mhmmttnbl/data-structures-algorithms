/**
 * @file queue/array/c/main.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>

#include "queue.h"

void display(int __x)
{ printf("Element-> %d\n", __x); }

int
main(int argc, char **argv)
{
  /* Initialize the queue */
  struct Queue *__queue = Queue_init();

  /* Push */
  __queue->push(__queue, 1);
  __queue->push(__queue, 2);
  __queue->push(__queue, 3);
  __queue->push(__queue, 4);
  __queue->push(__queue, 5);

  /* Fetch first element of the queue */
  printf("Front : %d\n", __queue->front(__queue));
  /* Fetch last element of the queue */
  printf("Back : %d\n", __queue->back(__queue));

  /* Traverse over the stack */
  __queue->traverse(__queue, display);
  
  /* Remove */
  __queue->pop(__queue);
  __queue->pop(__queue);

  printf("After pop...\n");

  /* Traverse over the stack */
  __queue->traverse(__queue, display);

  return(0);
}