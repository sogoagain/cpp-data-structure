//
//  BinaryTree.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 5..
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
using namespace std;

template <typename E>
class BinaryTree {
private:
    E data;
    BinaryTree* left;
    BinaryTree* right;
    
public:
    BinaryTree();
    BinaryTree(E item);
    ~BinaryTree();
    E getItem(void);
    void setItem(E item);
    BinaryTree* getLeftSubTree(void);
    BinaryTree* getRightSubTree(void);
    void connectLeftSubTree(BinaryTree* sub);
    void connectRightSubTree(BinaryTree* sub);
    void preorderTraverse(void (*action)(E item));
    void inorderTraverse(void (*action)(E item));
    void postorderTraverse(void (*action)(E item));
};

template <typename E>
BinaryTree<E>::BinaryTree() {
    left = NULL;
    right = NULL;
}

template <typename E>
BinaryTree<E>::BinaryTree(E item) {
    data = item;
    left = NULL;
    right = NULL;
}

template <typename E>
BinaryTree<E>::~BinaryTree() {
    if(left != NULL) {
        delete(this->left);
    }
    if(right != NULL) {
        delete(this->right);
    }
}

template <typename E>
E BinaryTree<E>::getItem(void) {
    return data;
}

template <typename E>
void BinaryTree<E>::setItem(E item) {
    data = item;
}

template <typename E>
typename BinaryTree<E>::BinaryTree* BinaryTree<E>::getLeftSubTree(void) {
    return left;
}

template <typename E>
typename BinaryTree<E>::BinaryTree* BinaryTree<E>::getRightSubTree(void) {
    return right;
}

template <typename E>
void BinaryTree<E>::connectLeftSubTree(BinaryTree* sub) {
    if(left != NULL) {
        delete left;
    }
    
    left = sub;
}

template <typename E>
void BinaryTree<E>::connectRightSubTree(BinaryTree* sub) {
    if(right != NULL) {
        delete right;
    }
    
    right = sub;
}

template <typename E>
void BinaryTree<E>::preorderTraverse(void (*action)(E item)) {
    action(data);
    
    if(left != NULL) {
        left->preorderTraverse(action);
    }
    if(right != NULL) {
        right->preorderTraverse(action);
    }
}

template <typename E>
void BinaryTree<E>::inorderTraverse(void (*action)(E item)) {
    if(left != NULL) {
        left->inorderTraverse(action);
    }
    
    action(data);
    
    if(right != NULL) {
        right->inorderTraverse(action);
    }
}

template <typename E>
void BinaryTree<E>::postorderTraverse(void (*action)(E item)) {
    if(left != NULL) {
        left->postorderTraverse(action);
    }
    
    if(right != NULL) {
        right->postorderTraverse(action);
    }
    
    action(data);
}

#endif /* BinaryTree_hpp */
