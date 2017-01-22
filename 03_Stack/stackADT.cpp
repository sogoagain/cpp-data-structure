//
//  stackADT.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 21..
//

#include <stdio.h>
#include <stdlib.h>
//#include "ArrayBaseStack/ArrayBaseStack.hpp"
#include "ListBaseStack/ListBaseStack.hpp"



int main(int argc, char** argv) {
    Stack<int> stack1, stack2;
    
    srand(time_t(NULL));
    
    printf("---stack1 push data---\n");
    for(int i = 0; i < 10; i++) {
        int item = rand()&10;
        printf("%d ", item);
        stack1.push(item);
    }
    printf("\n---------------------\n\n");
    
    printf("---stack1 peek data---\n");
    printf("%d\n", stack1.peek());
    printf("---------------------\n\n");
        
    printf("---stack2 = stack1---\n");
    stack2 = stack1;
    
    printf("---stack2 pop  data---\n");
    while(!stack2.isEmpty()) {
        printf("%d ", stack2.pop());
    }
    printf("\n---------------------\n\n");
    
    printf("---Stack<int> stack3 = stack1---\n");
    Stack<int> stack3 = stack1;
    printf("---------------------\n\n");
    
    printf("---stack3 pop  data---\n");
    while(!stack3.isEmpty()) {
        printf("%d ", stack3.pop());
    }
    printf("\n---------------------\n\n");
    
    return 0;
}
