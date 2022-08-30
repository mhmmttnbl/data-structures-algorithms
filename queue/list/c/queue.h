/**
 * @file queue/list/c/queue.h
 * @author TONBUL, Muhammet
 */

#ifndef __QUEUE_LIST__
#define __QUEUE_LIST__

typedef int Data;

struct Node;

struct Queue
{
  /**
   * @brief Add data to the end of the queue.
   * @param __this Reference to the queue.
   * @param __x  Data to be added.
   */
  void (*push)(struct Queue *__this, Data __x);
  
  /**
   * @brief Remove first element.
   * @param __this Reference to the queue.
   * @param __x  Data to be added.
   */
  void (*pop)(struct Queue *__this);
  
  /**
   * @brief Returns first element.
   * @param __this Reference to the queue.
   * @returns Returns data at the first element of the queue.
   */
  Data (*front)(struct Queue *__this);
  
  /**
   * @brief Returns last element.
   * @param __this Reference to the queue.
   * @returns Returns data at the last element of the queue.
   */
  Data (*back)(struct Queue *__this);
  
  /**
   * @brief Returns the number of elements in the queue.
   * @param __this Reference to the queue.
   * @returns Number of elements.
   */
  int (*size)(struct Queue *__this);
  
  /**
   * @brief Check whether the stack is queue.
   * @param __this Reference to the queue.
   * @returns 1 if the queue is empty, 0 if it's not.
   */
  int (*empty)(struct Queue *__this);
  
  /**
   * @brief Traverse over the queue.
   * @param  __this Reference to the queue.
   * @param __cb Callback function.
   */
  void (*traverse)(struct Queue *__this, void (*__cb)(Data __x));

  /* Reference to head */
  struct Node *_M_head;
  /* Reference to tail */
  struct Node *_M_tail;
  /* Reference to current */
  struct Node *_M_curr;
  /* Queue Size */
  int          _M_size;
};

void* Queue_init();

#endif /* !__QUEUE_LIST__ */