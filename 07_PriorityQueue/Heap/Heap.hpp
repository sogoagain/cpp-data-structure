//
//  Heap.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 9..
//

#ifndef Heap_hpp
#define Heap_hpp

#include <iostream>
using namespace std;

template <typename E>
class Heap {
private:
    static const int MAX_SIZE = 100;
    int maxSize;
    int size;
    int (*priorityCompare)(E data1, E data2);
    E* heapArray;
    
    inline bool isFull(void) {
        return maxSize == (size + 1);
    }
    inline int getParent(int index) {
        return index/2;
    }
    inline int getLeftChild(int index) {
        return index*2;
    }
    inline int getRightChild(int index) {
        return index*2 + 1;
    }
    int getHighPriorityChild(int index) {
        if(priorityCompare == NULL) {
            fprintf(stderr, "우선순위의 기준이 되는 함수가 등록되지 않았습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        if(getLeftChild(index) > size) {
            return 0;
        } else if(getLeftChild(index) == size) {
            return getLeftChild(index);
        } else {
            if(priorityCompare(getLeftChild(index), getRightChild(index)) >= 0) {
                return getLeftChild(index);
            } else {
                return getRightChild(index);
            }
        }
    }
    
public:
    Heap(int maxSize = MAX_SIZE, int (*priorityCompare)(E data1, E data2) = NULL): maxSize(maxSize), priorityCompare(priorityCompare) {
        heapArray = new E[maxSize];
        size = 0;
    }
    ~Heap() {
        delete[] heapArray;
    }
    bool isEmpty() {
        return size == 0;
    }
    void add(E item) {
        if(priorityCompare == NULL) {
            fprintf(stderr, "우선순위의 기준이 되는 함수가 등록되지 않았습니다.\n");
            exit(EXIT_FAILURE);
        }
        if(isFull()) {
            printf("Heap이 가득찼습니다.\n");
            return;
        }
        
        int index = ++size;
        
        while(index != 1) {
            if(priorityCompare(getParent(index), item) > 0) {
                heapArray[index] = heapArray[getParent(index)];
                index = getParent(index);
            } else {
                break;
            }
        }
        heapArray[index] = item;
    }
    
    E remove() {
        if(priorityCompare == NULL) {
            fprintf(stderr, "우선순위의 기준이 되는 함수가 등록되지 않았습니다.\n");
            exit(EXIT_FAILURE);
        }
        if(isEmpty()) {
            fprintf(stderr, "Heap이 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        int index = 1;
        int childIndex = 0;
        E deletedData = heapArray[index];
        heapArray[index] = heapArray[size--];
        
        while((childIndex = getHighPriorityChild(index))) {
            if(priorityCompare(heapArray[index], heapArray[childIndex]) >= 0) {
                break;
            }
            
            E temp = heapArray[childIndex];
            heapArray[childIndex] = heapArray[index];
            heapArray[index] = temp;
            
            index = childIndex;
        }
        
        return deletedData;
    }
    
};
#endif /* Heap_hpp */
