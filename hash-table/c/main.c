/**
 * @file hash-table/c/main.c
 * @author TONBUL, Muhammet
 */

#include <stdio.h>

#include "hash_table.h"

void display(const char *__k, Data __v)
{ printf("Key: %s <---> Value: %d\n", __k, __v); }

int
main(int argc, char **argv)
{
  /* Create pair */
  struct Pair __pair_x = {
    ._M_k = "AMAZON",
    ._M_x = 1
  };

  /* Create pair */
  struct Pair __pair_y = {
    ._M_k = "APPLE",
    ._M_x = 2
  };

  /* Create pair */
  struct Pair __pair_z = {
    ._M_k = "INTEL",
    ._M_x = 3
  };

  /* Initialize hash table */
  struct Hash_table *__table = Hash_table_init(10);

  /* Insert pair */
  __table->insert(__table, &__pair_x);
  /* Insert pair */
  __table->insert(__table, &__pair_y);
  /* Insert pair */
  __table->insert(__table, &__pair_z);
  
  /* Traverse over the hash table */
  __table->traverse(__table, display);

  /* Fetch data with given key */
  printf("Fetched-> %d\n", __table->find(__table, "AMAZON")->_M_x);
  /* Fetch data with given key */
  printf("Fetched-> %d\n", __table->find(__table, "APPLE")->_M_x);
  /* Fetch data with given key */
  printf("Fetched-> %d\n", __table->find(__table, "INTEL")->_M_x);

  /* Remove data with given key*/
  __table->remove(__table, "AMAZON");
  
  printf("After remove...\n");
  
  /* Traverse over the hash table */
  __table->traverse(__table, display);

  return(0);
}