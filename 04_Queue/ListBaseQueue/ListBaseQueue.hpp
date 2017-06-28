//
//  ListBaseQueue.hpp
//  DataStructure
//
//  Created by sogoagain on 2017. 1. 26..
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#include <algorithm>
#include <iostream>

using namespace std;

template <typename E>
class Queue {
private:
    class Node {
        friend class Queue;
    private:
        E data;
        Node* rightLink;
        Node* leftLink;
        
    public:
        Node(void) {
            rightLink = NULL;
            leftLink = NULL;
        }
        Node(E item, Node* previous, Node* next): data(item), rightLink(next), leftLink(previous) { }
    };
    
    Node* head;
    Node* tail;
    int size;
    
public:
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    Queue(const Queue<E>& copy) {
        head = NULL;
        tail = NULL;
        size = 0;
        
        Node* search = copy.head;
        
        while(search != NULL) {
            this->offer(search->data);
            search = search->rightLink;
            size++;
        }
    }
    ~Queue() {
        while(head != NULL) {
            Node* temp = head;
            head = temp->rightLink;
            delete temp;
        }
    }
    Queue<E>& operator=(const Queue<E>& reference) {
        Queue<E> temp = reference;
        size = temp.size;
        std::swap(temp.head, head);
        std::swap(temp.tail, tail);
        return *this;
    }
    
    bool isEmpty(void) {
        return (head == NULL);
    }
    void offer(E item) {
        tail = new Node(item, tail, NULL);
        
        if(head == NULL) {
            head = tail;
        } else {
            tail->leftLink->rightLink = tail;
        }
        
        size++;
    }
    E poll(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        Node* target = head;
        E polledItem = target->data;
        
        head = target->rightLink;
        
        if(head == NULL) {
            tail = NULL;
        }
        
        size--;
        delete target;
        return polledItem;
        
    }
    E peek(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return head->data;
    }
    int getSize(void) {
        return size;
    }
};


#endif /* ListBaseQueue_h */
