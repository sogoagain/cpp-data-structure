//
//  CircularQueue.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 25..
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include <algorithm>
using namespace std;

template <typename E>
class Queue {
private:
    static const int MAX_SIZE = 100;
    int maxSize;
    int front;
    int rear;
    E* storage;
    
    bool isFull(void) {
        return ((rear+1)%maxSize == front);
    }
    
public:
    Queue(int maxSize = MAX_SIZE):maxSize(maxSize) {
        storage = new E[maxSize];
        front = 0;
        rear = 0;
    }
    Queue(const Queue<E>& copy) {
        maxSize = copy.maxSize;
        front = copy.front;
        rear = copy.rear;
        
        storage = new E[maxSize];
        
        int i = front;
        do {
            i = (i + 1)%maxSize;
            storage[i] = copy.storage[i];
        } while(i != rear);
    }
    ~Queue() {
        delete[] storage;
    }
    Queue<E>& operator=(const Queue<E>& reference) {
        Queue temp = reference;
        
        maxSize = temp.maxSize;
        front = temp.front;
        rear = temp.rear;
        
        std::swap(temp.storage, storage);
        return *this;
    }
    
    bool isEmpty(void) {
        return (front == rear);
    }
    void offer(E item) {
        if(isFull()) {
            fprintf(stderr, "큐가 가득 찼습니다.\n");
            return;
        }
        
        rear = (rear+1)%maxSize;
        storage[rear] = item;
    }
    E peek(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return storage[(front+1)%maxSize];
    }
    E poll(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        front = (front+1)%maxSize;
        E target = storage[front];
        
        return target;
    }
};


#endif /* CircularQueue_h */
