/**
 * @file stack/list/c/stack.h
 * @author TONBUL, Muhammet
 */

#ifndef __STACK_LIST__
#define __STACK_LIST__

typedef int Data;

struct Node;

struct Stack
{
  /**
   * @brief Add data to the top of the stack.
   * @param __this Reference to the stack.
   * @param __x  Data to be added.
   */
  void (*push)(struct Stack *__this, Data __x);
  
  /**
   * @brief Removes first element.
   * @param __this Reference to the stack.
   */
  void (*pop)(struct Stack *__this);
  
  /**
   * @brief Removes first element.
   * @param __this Reference to the stack.
   * @returns Returns  data at the first element of the stack.
   */
  Data (*top)(struct Stack *__this);
  
  /**
   * @brief Returns the number of elements in the stack
   * @param __this Reference to the stack.
   * @returns Number of elements
   */
  int (*size)(struct Stack *__this);
  
  /**
   * @brief Check whether the stack is empty.
   * @param __this Reference to the stack.
   * @returns 1 if the stack is empty, 0 if it's not.
   */
  int (*empty)(struct Stack *__this);
  
  /**
   * @brief Traverse over the stack.
   * @param  __this Reference to the stack.
   * @param __cb Callback function.
   */
  void (*traverse)(struct Stack *__this, void (*__cb)(Data __x));

  /* Reference to head */
  struct Node *_M_head;
  /* Reference to tail */
  struct Node *_M_tail;
  /* Reference to current */
  struct Node *_M_curr;
  /* Size of the stack */
  int          _M_size;
};

/**
 * @brief Initializes the stack.
 * @returns Reference to allocated stack.
 */
void* Stack_init();

#endif /* !__STACK_LIST__ */