/**
 * @file stack/array/c/stack.h
 * @author TONBUL, Muhammet
 */

#ifndef __STACK_ARRAY__
#define __STACK_ARRAY__

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
   * @brief Returns first element.
   * @param __this Reference to the stack.
   * @returns Returns data at the first element of the stack.
   */
  Data (*top)(struct Stack *__this);
  
  /**
   * @brief Returns the number of elements in the stack.
   * @param __this Reference to the stack.
   * @returns Number of elements.
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

  /* Node pool */
  struct Node **_M_pool;
  /* Maximum size of the stack */
  int           _M_max;
  /* Index for top of the stack */
  int           _M_head;
};

/**
 * @brief Initializes the stack.
 * @param __x Number of elements.
 * @returns Reference to allocated stack.
 */
void* Stack_init(int __x);

#endif /* !__STACK_ARRAY__ */