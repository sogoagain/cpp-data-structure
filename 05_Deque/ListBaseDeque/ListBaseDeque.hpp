//
//  ListBaseDeque.hpp
//  DataStructure
//
//  Created by sogoagain on 2017. 2. 1..
//

#ifndef ListBaseDeque_h
#define ListBaseDeque_h

#include <algorithm>

using namespace std;

template <typename E>
class Deque {
private:
    class Node {
        friend class Deque;
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
    
public:
    Deque() {
        head = NULL;
        tail = NULL;
    }
    Deque(const Deque<E>& copy) {
        head = NULL;
        tail = NULL;
        
        Node* search = copy.head;
        
        while(search != NULL) {
            this->addLast(search->data);
            search = search->rightLink;
        }
    }
    ~Deque() {
        while(head != NULL) {
            Node* temp = head;
            head = temp->rightLink;
            delete temp;
        }
    }
    Deque<E>& operator=(const Deque<E>& reference) {
        Deque<E> temp = reference;
        std::swap(temp.head, head);
        std::swap(temp.tail, tail);
        return *this;
    }
    
    bool isEmpty(void) {
        return (head == NULL);
    }
    void addFirst(E item) {
        head = new Node(item, NULL, head);
        
        if(tail == NULL) {
            tail = head;
        } else {
            head->rightLink->leftLink = head;
        }
    }
    E removeFirst(void) {
        if(isEmpty()) {
            fprintf(stderr, "덱이 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        Node* target = head;
        E poppedItem = target->data;
        
        head = target->rightLink;
        
        if(head == NULL) {
            tail = NULL;
        }
        
        delete target;
        return poppedItem;
        
    }
    E getFirst(void) {
        if(isEmpty()) {
            fprintf(stderr, "덱이 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return head->data;
    }

    void addLast(E item) {
        tail = new Node(item, tail, NULL);
        
        if(head == NULL) {
            head = tail;
        } else {
            tail->leftLink->rightLink = tail;
        }
    }
    E removeLast(void) {
        if(isEmpty()) {
            fprintf(stderr, "덱가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        Node* target = tail;
        E polledItem = target->data;
        
        tail = target->leftLink;
        
        if(tail == NULL) {
            head = NULL;
        }
        
        delete target;
        return polledItem;
        
    }
    E getLast(void) {
        if(isEmpty()) {
            fprintf(stderr, "덱가 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return tail->data;
    }
};


#endif /* ListBaseDeque_h */
