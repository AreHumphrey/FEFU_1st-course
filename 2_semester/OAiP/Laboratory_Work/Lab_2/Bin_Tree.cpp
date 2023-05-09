#include "Bin_Tree.h"

#include <iostream>

class BinTree {
public:
    int value;

    class BinTree *left;

    class BinTree *right;
};
void DestroyBinTree(BinTree *root) {
    if (root != nullptr) {
        DestroyBinTree(root->left);
        DestroyBinTree(root->right);
        delete root;
    }
}
BinTree *CreateBinTree(int i) {
    BinTree *element = new BinTree;
    element->value = i;
    element->left = nullptr;
    element->right = nullptr;
    return element;
}

void Insert(BinTree *root, BinTree *element) {
    if (element->value < root->value) {
        if (root->left == nullptr) {
            root->left = element;
        } else {
            Insert(root->left, element);
        }
    } else {
        if (root->right == nullptr) {
            root->right = element;
        } else {
            Insert(root->right, element);
        }

    }
}

void Print(BinTree *currElem) {
    if (currElem->left != nullptr) {
        Print(currElem->left);
    }
    std::cout << currElem->value << std::endl;
    if (currElem->right != nullptr) {
        Print(currElem->right);
    }
}

void DeleteTree(BinTree *root) {
    if (root != nullptr) {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
    }
}

int Size(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + Size(root->left) + Size(root->right);
}

BinTree *Delete(BinTree *root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->value) {
        root->left = Delete(root->left, value);
    } else if (value > root->value)
        root->right = Delete(root->right, value);
    else {
        if (root->left == nullptr) {
            root->right = nullptr;

        } else if (root->right == nullptr) {
            root->left = nullptr;
        } else {
            BinTree *temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->value = temp->value;
            root->right = Delete(root->right, temp->value);
        }
    }
    return root;
}

BinTree *Search(BinTree *root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->value < value) {
        return Search(root->right, value);
    } else if (root->value > value) {
        return Search(root->left, value);
    } else {
        return root;
    }

}

