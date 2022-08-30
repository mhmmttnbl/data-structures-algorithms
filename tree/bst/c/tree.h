/**
 * @file bst/c/tree.h
 * @author TONBUL, Muhammet
 */

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

typedef int Data;

struct Node;

struct Tree
{
  /**
   * @brief Add data to the tree.
   * @param __this Reference to the tree.
   * @param __x  Data to be added.
   */
  void (*insert)(struct Tree *__this, Data __x);
  
  /**
   * @brief Removes data from the tree.
   * @param __this Reference to the tree.
   * @param __x  Data to be removed.
   */
  void (*remove)(struct Tree *__this, Data __x);
  
  /**
   * @brief Traverse tree left->root->right.
   * @param __this Reference to the tree.
   * @param __cb Callback function.
   */
  void (*inorder)(struct Tree *__this, void (*__cb)(Data __x));
  
  /**
   * @brief Traverse tree root->left->right.
   * @param __this Reference to the tree.
   * @param __cb Callback function.
   */
  void (*preorder)(struct Tree *__this, void (*__cb)(Data __x));
  
  /**
   * @brief Traverse tree left->right->root.
   * @param __this Reference to the tree.
   * @param __cb Callback function.
   */
  void (*postorder)(struct Tree *__this, void (*__cb)(Data __x));
  
  /**
   * @brief Find minimum data of the tree
   * @param __this Reference to the tree.
   * @returns Minimum value of the tree.
   */
  Data (*minimum)(struct Tree *__this);
  
  /**
   * @brief Find maximum data of the tree
   * @param __this Reference to the tree.
   * @returns Maximum value of the tree.
   */
  Data (*maximum)(struct Tree *__this);
  
  /* Reference to the root */
  struct Node *_M_root;
};

/**
 * @brief Initializes the tree.
 * @returns Reference to allocated tree.
 */
void* Tree_init();

#endif /* !__BINARY_SEARCH_TREE__ */