#ifndef BIN_TREE_STRUCT__LIBRARY_H
#define BIN_TREE_STRUCT__LIBRARY_H

class BinTree;
BinTree *CreateBinTree(int i);
void DestroyBinTree(BinTree *root);
void Insert(BinTree *root, BinTree *element);

void Print(BinTree *currElem);

void DeleteTree(BinTree *root);

int Size(BinTree *root);

BinTree *Delete(BinTree *root, int value);

BinTree *Search(BinTree *root, int value);

#endif //BIN_TREE_STRUCT__LIBRARY_H
