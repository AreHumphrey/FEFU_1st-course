#include "../AVL_Tree/library.h"

#include <iostream>

class AVLTree {
public:
    int key;
    AVLTree *parent;
    AVLTree *left;
    AVLTree *right;
    int balance;
};
void DestroyAVLTree(AVLTree *root) {
    if (root != nullptr) {
        DestroyAVLTree(root->left);
        DestroyAVLTree(root->right);
        delete root;
    }
}
int Size(AVLTree *elem) {
    if (elem == nullptr) {
        return 0;
    }
    return elem->balance;
}

AVLTree *NewNode(int key) {
    AVLTree *node = new AVLTree();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->balance = 1;
    return (node);
}

AVLTree *RightRotate(AVLTree *elem) {
    AVLTree *x = elem->left;
    AVLTree *y = x->right;
    x->right = elem;
    elem->left = y;
    elem->balance = std::max(Size(elem->left), Size(elem->right)) + 1;
    x->balance = std::max(Size(x->left), Size(x->right)) + 1;
    return x;

}

AVLTree *LeftRotate(AVLTree *elem) {
    AVLTree *y = elem->right;
    AVLTree *x = y->left;

    y->left = elem;
    elem->right = x;
    elem->balance = std::max(Size(elem->left), Size(elem->right)) + 1;
    x->balance = std::max(Size(x->left), Size(x->right)) + 1;
    return elem;
}

int GetBalance(AVLTree *n) {
    if (n == nullptr) {
        return 0;
    }
    return (Size(n->left) - Size(n->right));
}

AVLTree *Insert(AVLTree *node, int key) {

    if (node == nullptr) {
        return (NewNode(key));
    }
    if (key < node->key) {
        node->left = Insert(node->left, key);
    } else if (key > node->key) {
        node->right = Insert(node->right, key);
    } else {
        return node;
    }
    node->balance = 1 + std::max(Size(node->left), Size(node->right));
    int balance = GetBalance(node);
    if (balance > 1 && key < node->left->key) {
        return RightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return LeftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }
    return node;
}

AVLTree *MinValueNode(AVLTree *node) {
    AVLTree *current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

AVLTree *DeleteNode(AVLTree *root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {
        root->left = DeleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = DeleteNode(root->right, key);
    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLTree *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            AVLTree *temp = MinValueNode(root->right);
            root->key = temp->key;
            root->right = DeleteNode(root->right, temp->key);
        }
    }
    if (root == NULL) {
        return root;
    }
    root->balance = 1 + std::max(Size(root->left), Size(root->right));
    int balance = GetBalance(root);
    if (balance > 1 && GetBalance(root->left) >= 0) {
        return RightRotate(root);
    }
    if (balance > 1 && GetBalance(root->left) < 0) {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (balance < -1 && GetBalance(root->right) <= 0) {
        return LeftRotate(root);
    }
    if (balance < -1 && GetBalance(root->right) > 0) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
int FindNode(AVLTree *node, int key) {
    if (node == nullptr || node->key == key) {
        return node->key;
    } else if (key < node->key) {
        return FindNode(node->left, key);
    } else {
        return FindNode(node->right, key);
    }
}
void Print(AVLTree * root){
    if (root != nullptr){
        Print(root->left);
        std::cout << root->key << " ";
        Print(root->right);
    }
}

