/**
 * @file list/doubly/c/list.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct Node
{
  Data         _M_x;
  struct Node *_M_next;
  struct Node *_M_prev;
};

static void*
Node_init(Data __x, struct Node *__next, struct Node *__prev)
{
  struct Node *__this = malloc(sizeof(*__this));

  __this->_M_x = __x;
  __this->_M_next = __next;
  __this->_M_prev = __prev;

  return(__this);
}

static void
List_push_front(struct List *__this, Data __x)
{
  if (__this->_M_head != NULL) {
    __this->_M_head = Node_init(__x, __this->_M_head, NULL);
    __this->_M_head->_M_next->_M_prev = __this->_M_head;
  }
  else
    __this->_M_head = __this->_M_tail = Node_init(__x, NULL, NULL);
}

static void
List_push_back(struct List *__this, Data __x)
{
  if (__this->_M_tail != NULL) {
    __this->_M_tail = Node_init(__x, NULL, __this->_M_tail);
    __this->_M_tail->_M_prev->_M_next = __this->_M_tail;
  }
  else
    __this->_M_head = __this->_M_tail = Node_init(__x, NULL, NULL);
}

static void
List_pop_front(struct List *__this)
{
  if (__this->_M_head == __this->_M_tail) {
    free(__this->_M_head);
    __this->_M_head = __this->_M_tail = NULL;
  }
  else {
    __this->_M_head = __this->_M_head->_M_next;
    free(__this->_M_head->_M_prev);
    __this->_M_head->_M_prev = NULL;
  }
}

static void
List_pop_back(struct List *__this)
{
  if (__this->_M_head == __this->_M_tail) {
    free(__this->_M_head);
    __this->_M_head = __this->_M_tail = NULL;
  }
  else {
    __this->_M_tail = __this->_M_tail->_M_prev;
    free(__this->_M_tail->_M_next);
    __this->_M_tail->_M_next = NULL;   
  }
}

static void
List_remove(struct List *__this, Data __x)
{
  for (__this->_M_curr =__this->_M_head; __this->_M_curr != NULL;
    __this->_M_curr = __this->_M_curr->_M_next) {
    struct Node *__node = NULL;
    
    if (__this->_M_curr->_M_x == __x) {
      __node = __this->_M_curr;
      if (__this->_M_head == __node) {
        __this->_M_head = __node->_M_next;
        if (__this->_M_head != NULL)
          __this->_M_head->_M_prev = NULL;
      }
      else {
        __node->_M_prev->_M_next = __node->_M_next;
        if (__node->_M_next != NULL)
          __node->_M_next->_M_prev = __node->_M_prev;
      }
      
      __node->_M_next = __node->_M_prev = NULL;
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