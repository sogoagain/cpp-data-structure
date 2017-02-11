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
        return maxSize == size;
    }
    inline int getParentIndex(int index) {
        return index/2;
    }
    inline int getLeftChildIndex(int index) {
        return index*2;
    }
    inline int getRightChildIndex(int index) {
        return index*2 + 1;
    }
    int getHighPriorityChildIndex(int index) {
        if(priorityCompare == NULL) {
            fprintf(stderr, "우선순위의 기준이 되는 함수가 등록되지 않았습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        if(getLeftChildIndex(index) > size) {
            return 0;
        } else if(getLeftChildIndex(index) == size) {
            return getLeftChildIndex(index);
        } else {
            if(priorityCompare(heapArray[getLeftChildIndex(index)], heapArray[getRightChildIndex(index)]) >= 0) {
                return getLeftChildIndex(index);
            } else {
                return getRightChildIndex(index);
            }
        }
    }
    
public:
    Heap(int size = MAX_SIZE, int (*priorityCompare)(E data1, E data2) = NULL): maxSize(size), priorityCompare(priorityCompare) {
        heapArray = new E[maxSize+1];
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
            if(priorityCompare(item, heapArray[getParentIndex(index)]) > 0) {
                heapArray[index] = heapArray[getParentIndex(index)];
                index = getParentIndex(index);
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
        
        while((childIndex = getHighPriorityChildIndex(index))) {
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
    
    E getRoot(void) {
        if(isEmpty()) {
            fprintf(stderr, "Heap이 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return heapArray[1];
    }
};
#endif /* Heap_hpp */
