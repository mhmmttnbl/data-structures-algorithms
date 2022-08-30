/**
 * @file stack/array/c/stack.c
 * @author TONBUL, Muhammet
 */

#include <assert.h>
#include <stdlib.h>

#include "stack.h"

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
Stack_push(struct Stack *__this, Data __x)
{
  assert(__this->_M_head != __this->_M_max);
  
  __this->_M_pool[__this->_M_head++] = Node_init(__x);
}

static void
Stack_pop(struct Stack *__this)
{
  assert(__this->_M_head != 0);

  free(__this->_M_pool[--__this->_M_head]);
  __this->_M_pool[__this->_M_head] = NULL;
}

static Data
Stack_top(struct Stack *__this)
{ return(__this->_M_pool[__this->_M_head - 1]->_M_x); }

static int
Stack_size(struct Stack *__this)
{ return(__this->_M_head); }

static int
Stack_empty(struct Stack *__this)
{ return(__this->_M_head == 0); }

static void
Stack_traverse(struct Stack *__this, void (*__cb)(Data __x))
{
  for (int __i = 0; __i < __this->_M_head; ++__i)
    __cb(__this->_M_pool[__i]->_M_x);
}

static void
Stack_ctor(struct Stack *__this, int __x)
{
  __this->push = Stack_push;
  __this->pop = Stack_pop;
  __this->top = Stack_top;
  __this->size = Stack_size;
  __this->empty = Stack_empty;
  __this->traverse = Stack_traverse;

  __this->_M_head = 0;
  __this->_M_max = __x;
  __this->_M_pool = malloc(sizeof(struct Node*) * __this->_M_max);
}

void*
Stack_init(int __x)
{
  struct Stack *__this = malloc(sizeof(*__this));

  Stack_ctor(__this, __x);

  return(__this);
};