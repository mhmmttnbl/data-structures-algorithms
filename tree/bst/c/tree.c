/**
 * @file tree/bst/c/tree.c
 * @author TONBUL, Muhammet
 */

#include <stdlib.h>

#include "tree.h"

struct Node
{
  Data         _M_x;
  struct Node *_M_l;
  struct Node *_M_r;
};

static void*
Node_init(Data __x)
{
  struct Node *__this = malloc(sizeof(*__this));

  __this->_M_x = __x;
  __this->_M_l = NULL;
  __this->_M_r = NULL;

  return(__this);
}

static void
__impl_insert(struct Node **__obj, Data __x)
{
  if (*__obj == NULL) {
    *__obj = Node_init(__x);
  }
  else if ((*__obj)->_M_x > __x) {
    __impl_insert(&(*__obj)->_M_l, __x);
  }
  else if ((*__obj)->_M_x < __x) {
    __impl_insert(&(*__obj)->_M_r, __x);
  }
}

static struct Node*
__impl_minimum(struct Node *__obj)
{
  struct Node *__node = __obj;

  while (__node->_M_l != NULL)
    __node = __node->_M_l;

  return(__node);
}

static struct Node*
__impl_maximum(struct Node *__obj)
{
  struct Node *__node = __obj;

  while (__node->_M_r != NULL)
    __node = __node->_M_r;
  
  return(__node);
}

static struct Node* 
__impl_remove(struct Node *__obj, int __x)
{
	if (__obj == NULL) {
    return(__obj);
  }
	else if (__x < __obj->_M_x) {
    __obj->_M_l = __impl_remove(__obj->_M_l, __x);
  }
	else if (__x > __obj->_M_x) {
    __obj->_M_r = __impl_remove(__obj->_M_r, __x);
  }
	else {
		if (__obj->_M_l == NULL && __obj->_M_r == NULL) { 
			free(__obj); __obj = NULL;
		}
		else if(__obj->_M_l == NULL) {
			struct Node *__node = __obj;
			__obj = __obj->_M_r;
			
      free(__node);
		}
		else if(__obj->_M_r == NULL) {
			struct Node *__node = __obj;
			__obj = __obj->_M_l;
			
      free(__node);
		}
		else { 
			struct Node *__node = __impl_minimum(__obj->_M_r);
			
      __obj->_M_x = __node->_M_x;
			__obj->_M_r = __impl_remove(__obj->_M_r, __node->_M_x);
		}
	}

	return(__obj);
}

static void
__impl_inorder(struct Node *__obj, void (*__cb)(Data __x))
{
  if (__obj != NULL) {
    __impl_inorder(__obj->_M_l, __cb);
    __cb(__obj->_M_x);
    __impl_inorder(__obj->_M_r, __cb);
  }
}

static void
__impl_preorder(struct Node *__obj, void (*__cb)(Data __x))
{
  if (__obj != NULL) {
    __cb(__obj->_M_x);
    __impl_preorder(__obj->_M_l, __cb);
    __impl_preorder(__obj->_M_r, __cb);
  }
}

static void
__impl_postorder(struct Node *__obj, void (*__cb)(Data __x))
{
  if (__obj != NULL) {
    __impl_postorder(__obj->_M_l, __cb);
    __impl_postorder(__obj->_M_r, __cb);
    __cb(__obj->_M_x);
  }
}

static void
Tree_insert(struct Tree *__this, Data __x)
{ __impl_insert(&__this->_M_root, __x); }

static void
Tree_remove(struct Tree *__this, Data __x)
{ __impl_remove(__this->_M_root, __x); }

static void
Tree_inorder(struct Tree *__this, void (*__cb)(Data __x))
{ __impl_inorder(__this->_M_root, __cb); }

static void
Tree_preorder(struct Tree *__this, void (*__cb)(Data __x))
{ __impl_preorder(__this->_M_root, __cb); }

static void
Tree_postorder(struct Tree *__this, void (*__cb)(Data __x))
{ __impl_postorder(__this->_M_root, __cb); }

static Data
Tree_minimum(struct Tree *__this)
{ return(__impl_minimum(__this->_M_root)->_M_x); }

static Data
Tree_maximum(struct Tree *__this)
{ return(__impl_maximum(__this->_M_root)->_M_x); }

static void
Tree_ctor(struct Tree *__this)
{
  __this->insert = Tree_insert;
  __this->remove = Tree_remove;
  __this->inorder = Tree_inorder;
  __this->preorder = Tree_preorder;
  __this->postorder = Tree_postorder;
  __this->minimum = Tree_minimum;
  __this->maximum = Tree_maximum;

  __this->_M_root = NULL;
}

void* 
Tree_init()
{
  struct Tree *__this = malloc(sizeof(*__this));

  Tree_ctor(__this);

  return(__this);
}