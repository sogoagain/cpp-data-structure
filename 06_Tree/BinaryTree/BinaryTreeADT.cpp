//
//  BinaryTreeADT.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 5..
//

#include "BinaryTree.hpp"
#include <stdlib.h>

#define NUM_OF_NODE 13

void printData(int data) {
    printf("%d ", data);
}

int main(int argc, char** argv) {
    srand(time(NULL));
    BinaryTree<int>* tree[NUM_OF_NODE];
    
    printf("--- 노드 생성 ---\n");
    for(int i = 0; i < NUM_OF_NODE; i++) {
        int data = rand()%10;
        
        tree[i] = new BinaryTree<int>(data);
        printf("%d ", tree[i]->getItem());
    }
    printf("\n---------------\n");
    
    printf("--- 노드 연결 ---\n");
    for(int i = 0; i < NUM_OF_NODE/2; i++) {
        int subTreeIndex = i*2 + 1;
        tree[i]->connectLeftSubTree(tree[subTreeIndex]);
        printf("%d번 왼쪽에 %d번 서브트리 연결 성공\n", i, subTreeIndex);
        
        subTreeIndex = subTreeIndex + 1;
        if(subTreeIndex < NUM_OF_NODE) {
            tree[i]->connectRightSubTree(tree[i*2 + 2]);
            printf("%d번 오른쪽에 %d번 서브트리 연결 성공\n", i, subTreeIndex);
        }
    }
    printf("---------------\n");
    
    printf("0번 루트에서 후위 순회\n");
    tree[0]->postorderTraverse(printData);
    printf("\n");
    
    printf("1번 루트에서 전위 순회\n");
    tree[1]->preorderTraverse(printData);
    printf("\n");
    
    printf("4번 루트에서 중위 순회\n");
    tree[4]->inorderTraverse(printData);
    printf("\n");
    
    delete tree[0];
    return 0;
}
