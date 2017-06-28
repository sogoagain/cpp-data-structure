//
//  Heap.cpp
//  DataStructure
//
//  Created by sogoagain on 2017. 2. 9..
//

#include "Heap.hpp"

int getPriority(char data1, char data2) {
    return data2 - data1;
}

int main(int argc, char** argv) {
    Heap<char> heap(6, getPriority);
    
    heap.add('A');
    heap.add('B');
    heap.add('C');
    printf("%c\n", heap.remove());
    
    heap.add('A');
    heap.add('B');
    heap.add('C');
    printf("%c\n", heap.remove());
    
    while(!heap.isEmpty()) {
        printf("%c ", heap.remove());
    }
    printf("\n");
    
    return 0;
}
