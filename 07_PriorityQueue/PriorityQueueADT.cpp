//
//  PriorityQueue.cpp
//  DataStructure
//
//  Created by sogoagain on 2017. 2. 11..
//

#include "PriorityQueue.hpp"

int getPriority(char data1, char data2) {
    return data2 - data1;
}

int main(int argc, char** argv) {
    PriorityQueue<char> priorityQueue(10, getPriority);
    
    priorityQueue.offer('A');
    priorityQueue.offer('B');
    priorityQueue.offer('C');
    printf("%c\n", priorityQueue.poll());
    
    priorityQueue.offer('A');
    priorityQueue.offer('B');
    priorityQueue.offer('C');
    printf("%c\n", priorityQueue.peek());
    
    while(!priorityQueue.isEmpty()) {
        printf("%c ", priorityQueue.poll());
    }
    printf("\n");
    
    return 0;
}
