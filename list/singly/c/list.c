/**
 * @file list/singly/c/list.c
 * @author TONBUL, Muhammet
 */

#include <stdlib.h>

#include "list.h"

struct Node
{
  Data         _M_x;
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
List_push_front(struct List *__this, Data __x)
{
  __this->_M_head = Node_init(__x, __this->_M_head);

  if (__this->_M_tail == NULL)
    __this->_M_tail = __this->_M_head;
}

static void
List_push_back(struct List *__this, Data __x)
{
  if (__this->_M_tail != NULL) {
    __this->_M_tail->_M_next = Node_init(__x, NULL);
    __this->_M_tail = __this->_M_tail->_M_next;
  }
  else {
    __this->_M_head = __this->_M_tail = Node_init(__x, NULL);
  }
}

static void
List_pop_front(struct List *__this)
{
  struct Node *__node = __this->_M_head;

  if (__this->_M_head == __this->_M_tail)
    __this->_M_head = __this->_M_tail = NULL;
  else
    __this->_M_head = __this->_M_head->_M_next;

  free(__node);
}

static void
List_pop_back(struct List *__this)
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
}

static void
List_remove(struct List *__this, Data __x)
{
  if (__this->_M_head != NULL) {
    if (__this->_M_head == __this->_M_tail && __x == __this->_M_head->_M_x) {
      free(__this->_M_head);

      __this->_M_head = __this->_M_tail = NULL;
    }
    else if (__x == __this->_M_head->_M_x) {
      struct Node *__node = __this->_M_head;
      __this->_M_head = __this->_M_head->_M_next;

      free(__node);
    }
    else {
      struct Node *__prev, *__node;

      for (__prev = __this->_M_head, __node = __this->_M_head->_M_next;
        __node != NULL && !(__node->_M_x == __x);
        __prev = __prev->_M_next, __node = __node->_M_next);

      if (__node != NULL) {
        __prev->_M_next = __node->_M_next;

        if (__prev == __this->_M_tail)
          __this->_M_tail = __prev;
          
        free(__node);
      }
    }
  }
}

static void
List_move_to_head(struct List *__this)
{ __this->_M_curr = __this->_M_head; }

static void
List_move_to_tail(struct List *__this)
{ __this->_M_curr = __this->_M_tail; }

static Data
List_front(struct List *__this)
{
  List_move_to_head(__this);

  return(__this->_M_head->_M_x);
} 

static Data
List_back(struct List *__this)
{
  List_move_to_tail(__this);

  return(__this->_M_curr->_M_x);
}

static void
List_traverse(struct List *__this, void (*__cb)(Data __x))
{
  List_move_to_head(__this);

  for (; __this->_M_curr != NULL; __this->_M_curr = __this->_M_curr->_M_next)
    __cb(__this->_M_curr->_M_x);
}

static void
List_clear(struct List *__this)
{
  while (__this->_M_head != NULL) {
    __this->_M_curr = __this->_M_head;
    __this->_M_head = __this->_M_head->_M_next;

    free(__this->_M_curr);
  }
}

static void
List_ctor(struct List *__this)
{
  __this->push_front = List_push_front;
  __this->push_back = List_push_back;
  __this->pop_front = List_pop_front;
  __this->pop_back = List_pop_back;
  __this->remove = List_remove;
  __this->front = List_front;
  __this->back = List_back;
  __this->move_to_head = List_move_to_head;
  __this->move_to_tail = List_move_to_tail;
  __this->traverse = List_traverse;
  __this->clear = List_clear;

  __this->_M_head = NULL;
  __this->_M_tail = NULL;
  __this->_M_curr = NULL;
}

void*
List_init()
{
  struct List *__this = malloc(sizeof(*__this));

  List_ctor(__this);

  return(__this);
}