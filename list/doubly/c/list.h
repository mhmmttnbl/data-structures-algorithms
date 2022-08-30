/**
 * @file list/doubly/c/list.h
 * @author TONBUL, Muhammet
 */

#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__

typedef int Data;

struct Node;

struct List
{
  /**
   * @brief  Add data to the front of the list.
   * @param  __this Reference to the list.
   * @param  __x  Data to be added.
   */
  void (*push_front)(struct List *__this, Data __x);
  
  /**
   * @brief  Add data to the back of the list.
   * @param  __this Reference to the list.
   * @param  __x  Data to be added.
   */
  void (*push_back)(struct List *__this, Data __x);

  /**
   * @brief  Remove first element of the list.
   * @param  __this Reference to the list.
   */
  void (*pop_front)(struct List *__this);
  
  /**
   * @brief  Remove last element of the list.
   * @param  __this Reference to the list.
   */
  void (*pop_back)(struct List *__this);

  /**
   * @brief  Remove data of the list.
   * @param  __this Reference to the list.
   * @param  __x  Data to be removed.
   */ 
  void (*remove)(struct List *__this, Data __x);

  /**
   * @brief  Move current reference to head.
   * @param  __this Reference to the list.
   */ 
  void (*move_to_head)(struct List *__this);
  
  /**
   * @brief  Move current reference to tail.
   * @param  __this Reference to the list.
   */ 
  void (*move_to_tail)(struct List *__this);
  
  /**
   * @brief Returns data at the first element of the list.
   * @param  __this Reference to the list.
   * @returns Data of the first element.
   */
  Data (*front)(struct List *__this);
  
  /**
   * @brief Returns data at the last element of the list.
   * @param  __this Reference to the list.
   * @returns Data of the last element.
   */
  Data (*back)(struct List *__this);
  
  /**
   * @brief Traverse over list.
   * @param  __this Reference to the list
   * @param __cb Callback function.
   */
  void (*traverse)(struct List *__this, void (*__cb)(Data __x));
  
  /**
   * @brief Remove all element from the list.
   * @param  __this Reference to the list.
   */
  void (*clear)(struct List *__this);

  /* Reference to head */
  struct Node *_M_head;
  /* Reference to tail */
  struct Node *_M_tail;
  /* Reference to current */
  struct Node *_M_curr;
};

/**
 * @brief Initializes the list
 * @returns Reference to allocated list
 */
void* List_init();

#endif /* !__DOUBLY_LINKED_LIST__ */