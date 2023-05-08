#ifndef AVL_TREE_LIBRARY_H
#define AVL_TREE_LIBRARY_H

class AVLTree;
void DestroyAVLTree(AVLTree *root);
int Size(AVLTree *elem);
AVLTree *NewNode(int key);
AVLTree *RightRotate(AVLTree *elem);
AVLTree *LeftRotate(AVLTree *elem);
int GetBalance(AVLTree *n);
AVLTree *Insert(AVLTree *node, int key);
AVLTree *DeleteNode(AVLTree *root, int key);
AVLTree *FindNode(AVLTree *node, int key);
void Print(AVLTree * root);

#endif //AVL_TREE_LIBRARY_H
