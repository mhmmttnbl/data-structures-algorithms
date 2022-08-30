/**
 * @file hash-table/c/hash_table.h
 * @author TONBUL, Muhammet
 */

#ifndef __HASH_TABLE__
#define __HASH_TABLE__

typedef int Data;

/* Pair */
struct Pair
{
  /* Key */
  char *_M_k;
  /* Data */
  Data  _M_x;
};

struct Hash_table
{
  /**
   * @brief Add pair to the hash table.
   * @param __this Reference to the stack.
   * @param __obj  Pair object to be added.
   */
  void (*insert)(struct Hash_table *__this, struct Pair *__obj);
  
  /**
   * @brief Removes pair with given key.
   * @param __this Reference to the stack.
   * @param __x Key.
   */
  void (*remove)(struct Hash_table *__this, char const *__x);
  
  /**
   * @brief Find pair with given key.
   * @param __this Reference to the stack.
   * @param __obj  Key.
   */
  struct Pair* (*find)(struct Hash_table *__this, char const *__x);

  /**
   * @brief Traverse over the hash table.
   * @param  __this Reference to the stack.
   * @param __cb Callback function.
   */
  void (*traverse)(struct Hash_table *__this, void (*__cb)(char const *__k, Data __x));

  /* Reference to node pool */
  struct Node **_M_pool;
  /* Hash table size */
  int           _M_size;
};

/**
 * @brief Initializes the hash table.
 * @returns Reference to allocated hash table.
 */
void* Hash_table_init(int __x);

#endif /* !__HASH_TABLE__ */