/**
 * @file hash-table/c/hash_table.c
 * @author TONBUL, Muhammet
 */

#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

struct Node
{
  struct Pair *_M_obj;
};

static void
__impl_set_first(struct Node *__node, char *__x)
{ 
  __node->_M_obj->_M_k = malloc(strlen(__x) + 1);
  strcpy(__node->_M_obj->_M_k, __x);
}

static void
__impl_set_second(struct Node *__node, Data __x)
{ __node->_M_obj->_M_x = __x; }

static char*
__impl_get_first(struct Node *__node)
{ return(__node->_M_obj->_M_k); }

static Data
__impl_get_second(struct Node *__node)
{ return(__node->_M_obj->_M_x); }

static struct Pair*
__impl_get_pair(struct Node *__node)
{ return(__node->_M_obj); }

static void
__impl_alloc_pair(struct Node *__node)
{ __node->_M_obj = malloc(sizeof(*__node->_M_obj)); }

static void
__impl_alloc_pool(struct Hash_table *__this)
{
  __this->_M_pool = malloc(sizeof(struct Node*) * __this->_M_size);

  for (int __i = 0; __i < __this->_M_size; ++__i)
    __this->_M_pool[__i] = NULL;
}

static unsigned int
__impl_hash(struct Hash_table *__this, const char *__x)
{
  unsigned int __a = 31415, __b = 27183, __h;
  
  for (__h = 0; *__x != '\0'; __x++, __a = __a * __b % __this->_M_size - 1)
    __h = (__a * __h + *__x) % __this->_M_size;
  
  return(__h);
}

static void*
Node_init(struct Pair *__obj)
{
  struct Node *__this = malloc(sizeof(*__this));

  __impl_alloc_pair(__this);
  __impl_set_first(__this, __obj->_M_k);
  __impl_set_second(__this, __obj->_M_x);

  return(__this);
}

static void 
Node_free(struct Node **__node)
{
  free((*__node)->_M_obj->_M_k);
  free((*__node)->_M_obj);
  free((*__node));

  *__node = NULL;
}

static void
Hash_table_insert(struct Hash_table *__this, struct Pair *__obj)
{ 
  unsigned int __i = __impl_hash(__this, __obj->_M_k);
  
  __this->_M_pool[__i] = Node_init(__obj); 
}

static void
Hash_table_remove(struct Hash_table *__this, char const *__x)
{
  unsigned int __i = __impl_hash(__this, __x);

  if (__this->_M_pool[__i] != NULL &&
    strcmp(__impl_get_first(__this->_M_pool[__i]), __x) == 0)
      Node_free(&__this->_M_pool[__i]);
}

static struct Pair*
Hash_table_find(struct Hash_table *__this, char const *__x)
{
  unsigned int __i = __impl_hash(__this, __x);

  if (__this->_M_pool[__i] != NULL &&
    strcmp(__impl_get_first(__this->_M_pool[__i]), __x) == 0)
      return(__impl_get_pair(__this->_M_pool[__i]));
  else
    return(NULL);
}

static void
Hash_table_traverse(struct Hash_table *__this, void (*__cb)(char const *__k, Data __v))
{
  for (int __i = 0; __i < __this->_M_size; ++__i) {
    if (__this->_M_pool[__i] != NULL)
      __cb(__impl_get_first(__this->_M_pool[__i]), 
           __impl_get_second(__this->_M_pool[__i]));
  }
}

static void
Hash_table_ctor(struct Hash_table *__this, int __x)
{
  __this->insert = Hash_table_insert;
  __this->remove = Hash_table_remove;
  __this->find = Hash_table_find;
  __this->traverse = Hash_table_traverse;

  __this->_M_size = __x;
  __impl_alloc_pool(__this);
}

void*
Hash_table_init(int __x)
{
  struct Hash_table *__this = malloc(sizeof(*__this));

  Hash_table_ctor(__this, __x);

  return(__this);
}