//
//  ListBaseQueue.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 26..
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#include <algorithm>

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
        }
        Node(E item, Node* previous, Node* next): data(item), rightLink(next), leftLink(previous) { }
    };
    
    Node* head;
    Node* tail;
    
public:
    Queue() {
        head = new Node();  // 더미노드 추가
        tail = new Node();
        head->leftLink = NULL;
        head->rightLink = tail;
        tail->leftLink = head;
        tail->rightLink = NULL;
    }
    Queue(const Queue<E>& copy) {
        head = new Node();  // 더미노드 추가
        tail = new Node();
        head->leftLink = NULL;
        head->rightLink = tail;
        tail->leftLink = head;
        tail->rightLink = NULL;
        
        Node* search = copy.head;
        
        while(search->rightLink != copy.tail) {
            search = search->rightLink;
            tail->leftLink->rightLink = new Node(search->data, tail->leftLink, tail);
            tail->leftLink = tail->leftLink->rightLink;
        }
    }
    ~Queue() {
        while(head->rightLink != NULL) {
            Node* temp = head->rightLink;
            head->rightLink = temp->rightLink;
            delete temp;
        }
        delete head;
    }
    Queue<E>& operator=(const Queue<E>& reference) {
        Queue<E> temp = reference;
        std::swap(temp.head, head);
        std::swap(temp.tail, tail);
        return *this;
    }
    
    bool isEmpty(void) {
        return (head->rightLink == tail);
    }
    void offer(E item) {
        tail->leftLink->rightLink = new Node(item, tail->leftLink, tail);
        tail->leftLink = tail->leftLink->rightLink;
    }
    E poll(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        Node* target = head->rightLink;
        E poppedItem = target->data;
        
        head->rightLink = target->rightLink;
        
        delete target;
        return poppedItem;
        
    }
    E peek(void) {
        if(isEmpty()) {
            fprintf(stderr, "큐가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return (head->rightLink)->data;
    }
};


#endif /* ListBaseQueue_h */
