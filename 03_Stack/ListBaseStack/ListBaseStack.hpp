//
//  ListBaseStack.hpp
//  DataStructure
//
//  Created by sogoesagain on 2017. 1. 22..
//

#ifndef ListBaseStack_h
#define ListBaseStack_h

#include <algorithm>

using namespace std;

template <typename E>
class Stack {
private:
    class Node {
        friend class Stack;
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
    Stack() {
        head = new Node();  // 더미노드 추가
        tail = new Node();
        head->leftLink = NULL;
        head->rightLink = tail;
        tail->leftLink = head;
        tail->rightLink = NULL;
    }
    Stack(const Stack<E>& copy) {
        head = new Node();  // 더미노드 추가
        tail = new Node();
        head->leftLink = NULL;
        head->rightLink = tail;
        tail->leftLink = head;
        tail->rightLink = NULL;
        
        Node* search = copy.tail;
        
        while(search->leftLink != copy.head) {
            search = search->leftLink;
            head->rightLink->leftLink = new Node(search->data, head, head->rightLink);
            head->rightLink = head->rightLink->leftLink;
        }
    }
    ~Stack() {
        while(head->rightLink != NULL) {
            Node* temp = head->rightLink;
            head->rightLink = temp->rightLink;
            delete temp;
        }
        delete head;
    }
    Stack<E>& operator=(const Stack<E>& reference) {
        Stack<E> temp = reference;
        std::swap(temp.head, head);
        std::swap(temp.tail, tail);
        return *this;
    }
    
    bool isEmpty(void) {
        return (head->rightLink == tail);
    }
    void push(E item) {
        head->rightLink->leftLink = new Node(item, head, head->rightLink);
        head->rightLink = head->rightLink->leftLink;
    }
    E pop(void) {
        if(isEmpty()) {
            fprintf(stderr, "스택이 비어있습니다.\n");
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
            fprintf(stderr, "스택이 비어있습니다.\n");
            exit(EXIT_FAILURE);
        }
        
        return (head->rightLink)->data;
    }
};

#endif /* ListBaseStack_h */
