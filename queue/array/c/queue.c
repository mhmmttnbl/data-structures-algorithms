/**
 * @file queue/array/c/queue.c
 * @author TONBUL, Muhammet
 */

#include <assert.h>
#include <stdlib.h>

#include "queue.h"

struct Node
{
  Data _M_x;
};

static void*
Node_init(Data __x)
{
  struct Node *__this = malloc(sizeof(*__this));

  __this->_M_x = __x;

  return(__this);
}

static void
Queue_push(struct Queue *__this, Data __x)
{
  assert((__this->_M_rear + 2) % __this->_M_max != __this->_M_front);

  __this->_M_rear = (__this->_M_rear + 1) % __this->_M_max;
  __this->_M_pool[__this->_M_rear] = Node_init(__x);
}

static void
Queue_pop(struct Queue *__this)
{
  free(__this->_M_pool[__this->_M_front]);
  
  __this->_M_pool[__this->_M_front] = NULL;
  __this->_M_front = (__this->_M_front + 1) % __this->_M_max;
}

static Data
Queue_front(struct Queue *__this)
{ return(__this->_M_pool[__this->_M_front]->_M_x); }

static Data
Queue_back(struct Queue *__this)
{ return(__this->_M_pool[__this->_M_rear]->_M_x); }

static int
Queue_size(struct Queue *__this)
{ 
  return(((__this->_M_rear + __this->_M_max) -
           __this->_M_front + 1) % __this->_M_max);
}

static int
Queue_empty(struct Queue *__this)
{ return(__this->_M_front == 0); }

static void
Queue_traverse(struct Queue *__this, void (*__cb)(Data __x))
{
  for (int __i = __this->_M_front; __i <= __this->_M_rear; ++__i)
    __cb(__this->_M_pool[__i]->_M_x);
}

static void
Queue_ctor(struct Queue *__this, int __x)
{
  __this->push = Queue_push;
  __this->pop = Queue_pop;
  __this->front = Queue_front;
  __this->back = Queue_back;
  __this->size = Queue_size;
  __this->empty = Queue_empty;
  __this->traverse = Queue_traverse;
  
  __this->_M_front = 1;
  __this->_M_rear = 0;
  __this->_M_max = __x + 1;
  __this->_M_pool = malloc(sizeof(struct Node*) * __this->_M_max);
}

void* 
Queue_init(int __x)
{
  struct Queue *__this = malloc(sizeof(*__this));

  Queue_ctor(__this, __x);

  return(__this);
}