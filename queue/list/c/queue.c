/**
 * @file queue/list/c/queue.c
 * @author TONBUL, Muhammet
 */

#include <stdlib.h>

#include "queue.h"

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
Queue_push(struct Queue *__this, Data __x)
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
Queue_pop(struct Queue *__this)
{
  struct Node *__node = __this->_M_head;

  if (__this->_M_head == __this->_M_tail)
    __this->_M_head = __this->_M_tail = NULL;
  else
    __this->_M_head = __this->_M_head->_M_next;

  free(__node);

  __this->_M_size--;
}

static Data
Queue_front(struct Queue *__this)
{ return(__this->_M_head->_M_x); }

static Data
Queue_back(struct Queue *__this)
{ return(__this->_M_tail->_M_x); }

static int
Queue_size(struct Queue *__this)
{ return(__this->_M_size); }

static int
Queue_empty(struct Queue *__this)
{ return(__this->_M_head == NULL); }

static void
Queue_traverse(struct Queue *__this, void (*__cb)(Data __x))
{
  for (__this->_M_curr = __this->_M_head; __this->_M_curr != NULL; 
    __this->_M_curr = __this->_M_curr->_M_next)
    __cb(__this->_M_curr->_M_x);
}

static void
Queue_ctor(struct Queue *__this)
{
  __this->push = Queue_push;
  __this->pop = Queue_pop;
  __this->front = Queue_front;
  __this->back = Queue_back;
  __this->size = Queue_size;
  __this->empty = Queue_empty;
  __this->traverse = Queue_traverse;

  __this->_M_head = NULL;
  __this->_M_tail = NULL;
  __this->_M_curr = NULL;
  __this->_M_size = 0;
}

void*
Queue_init()
{
  struct Queue *__this = malloc(sizeof(*__this));

  Queue_ctor(__this);

  return(__this);
}