/**
 * @file queue/array/c/queue.h
 * @author TONBUL, Muhammet
 */

#ifndef __QUEUE_ARRAY__
#define __QUEUE_ARRAY__

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

  /* Node pool */
  struct Node **_M_pool;
  /* Index for head of the queue */
  int           _M_front;
  /* Index for last of the queue */
  int           _M_rear;
  /* Maximum size of the queue */
  int           _M_max;
};

void* Queue_init(int __x);

#endif /* !__QUEUE_ARRAY__ */