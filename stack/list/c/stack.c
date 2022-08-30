/**
 * @file stack/list/c/stack.c
 * @author TONBUL, Muhammet
 */

#include "stack.h"

#include <stdlib.h>

struct Node
{
  Data _M_x;
  struct Node *_M_next;
};

static void*
Node_init(Data __x, struct Node *__obj)
{
  struct Node *__this = malloc(sizeof(*__this));

  __this->_M_x = __x;
  __this->_M_next = __obj;

  return(__this);
}

static void
Stack_push(struct Stack *__this, Data __x)
{
  if (__this->_M_tail != NULL) {
    __this->_M_tail->_M_next = Node_init(__x, NULL);
    __this->_M_tail = __this->_M_tail->_M_next;
  }
  else {
    __this->_M_head = __this->_M_tail = Node_init(__x, NULL);
  }

  __this->_M_size++;
}

static void
Stack_pop(struct Stack *__this)
{
  if (__this->_M_head == __this->_M_tail) {
    free(__this->_M_head);
    __this->_M_head = __this->_M_tail = NULL;
  }
  else {
    struct Node *__node;

    for (__node = __this->_M_head; __node->_M_next != __this->_M_tail; 
      __node = __node->_M_next);

    free(__this->_M_tail);

    __this->_M_tail = __node;
    __this->_M_tail->_M_next = NULL;
  }
  
  __this->_M_size--;
}

static Data
Stack_top(struct Stack *__this)
{ return(__this->_M_tail->_M_x); }

static int
Stack_size(struct Stack *__this)
{ return(__this->_M_size); }

static int
Stack_empty(struct Stack *__this)
{ return(__this->_M_head == NULL); }

static void
Stack_traverse(struct Stack *__this, void (*__cb)(Data __x))
{
  for (__this->_M_curr = __this->_M_head; __this->_M_curr != NULL; 
    __this->_M_curr = __this->_M_curr->_M_next)
    __cb(__this->_M_curr->_M_x);
}

static void
Stack_ctor(struct Stack *__this)
{
  __this->push = Stack_push;
  __this->pop = Stack_pop;
  __this->top = Stack_top;
  __this->size = Stack_size;
  __this->empty = Stack_empty;
  __this->traverse = Stack_traverse;

  __this->_M_head = NULL;
  __this->_M_tail = NULL;
  __this->_M_curr = NULL;
  __this->_M_size = 0;
}

void*
Stack_init()
{
  struct Stack *__this = malloc(sizeof(*__this));

  Stack_ctor(__this);

  return(__this);
}