//
//  Heap.cpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 9..
//

#include "Heap.hpp"

int getPriority(char data1, char data2) {
    return data1- data2;
}

int main(int argc, char** argv) {
    Heap<int> heap(100, getPriority);
    
    
    
    return 0;
}
