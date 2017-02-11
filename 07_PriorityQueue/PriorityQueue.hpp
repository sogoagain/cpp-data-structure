//
//  PriorityQueue.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 2. 11..
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include "Heap/Heap.hpp"

template <typename E>
class PriorityQueue {
private:
    static const int MAX_SIZE = 100;
    Heap<E>* heap;
public:
    PriorityQueue(int size = MAX_SIZE, int (*priorityCompare)(E data1, E data2) = NULL) {
        heap = new Heap<E>(size, priorityCompare);
    }
    ~PriorityQueue() {
        delete heap;
    }
    bool isEmpty(void) {
        return heap->isEmpty();
    }
    void offer(E item) {
        heap->add(item);
    }
    E peek(void) {
        return heap->getRoot();
    }
    E poll(void) {
        return heap->remove();
    }
};

#endif /* PriorityQueue_hpp */
