/**
 * @file tree/bst/c/main.c
 * @author TONBUL, Muhammet
 */
#include <stdio.h>

#include "tree.h"

void display(Data __x)
{ printf("Element-> %d\n", __x); }

int
main(int argc, char **argv)
{
  /* Initialize the tree */
  struct Tree *__tree = Tree_init();

  /* Insert data */ 
  __tree->insert(__tree, 0);
  __tree->insert(__tree, 1);
  __tree->insert(__tree, 2);
  __tree->insert(__tree, 3);
  __tree->insert(__tree, 4);
  __tree->insert(__tree, 5);
  __tree->insert(__tree, 6);
  __tree->insert(__tree, 7);
  __tree->insert(__tree, 8);
  __tree->insert(__tree, 9);

  /* Fetch minimum value */
  printf("Minimum-> %d\n", __tree->minimum(__tree));
  /* Fetch maximum value */
  printf("Maximum-> %d\n", __tree->maximum(__tree));

  /* Choose one of the traversal methods */
  __tree->inorder(__tree, display);
  // __tree->preorder(__tree, display);
  // __tree->postorder(__tree, display);

  /* Remove data */
  __tree->remove(__tree, 2);
  __tree->remove(__tree, 3);

  printf("After remove...\n");

  /* Choose one of the traversal methods */
  // __tree->inorder(__tree, display);
   __tree->preorder(__tree, display);
  // __tree->postorder(__tree, display);

  return(0);
}

