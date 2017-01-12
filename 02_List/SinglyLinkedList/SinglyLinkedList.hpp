#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
    private:
        class Node {
            friend class LinkedList;
            private:
                T data;
                Node* link;
            
            public:
                Node(void) {
                    data = NULL;
                    link = NULL;
                }
                Node(T item, Node* next) {
                    data = item;
                    link = next;
                }
        };

        Node* head;
        Node* current;
        Node* previous;
        int size;
        int (*compare)(T item1, T item2);

    public:
        LinkedList();
        LinkedList(const LinkedList<T>& copy);
        ~LinkedList();
        LinkedList<T>& operator=(const LinkedList<T>& reference);

        bool isEmpty(void);
        void add(T item);
        void add(int index, T item);
        void set(int index, T item);
        T remove(int index);
        T remove(void);
        T getItem(int index);
        T getItem(void);
        int getSize(void);
        int indexOf(T item);
        int lastIndexOf(T item);
    
        bool hasNext(void);
        T first(void);
        T next(void);
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = new Node();  // 더미노드 추가

    current = head;
    previous = NULL;
    size = 0;
    compare = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy) {
}

template <typename T>
LinkedList<T>::~LinkedList() {
    delete head;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& reference) {
}

template <typename T>
bool LinkedList<T>::isEmpty(void) {
    return (head->link == NULL);
}

template <typename T>
void LinkedList<T>::add(int index, T item) {

}

template <typename T>
void LinkedList<T>::add(T item) {
    head->link = new Node(item, head->link);
    size++;
}

template <typename T>
void LinkedList<T>::set(int index, T item) {

}

template <typename T>
T LinkedList<T>::remove(int index) {

}

template <typename T>
T LinkedList<T>::remove(void) {
    if(isEmpty()) {
        printf("삭제할 데이터가 없습니다.\n");
        exit(1);
    }

    T target;
    target = current->data;
    previous->link = current->link;
    
    delete current;
    current = previous;

    size--;
    return target;
}

template <typename T>
T LinkedList<T>::getItem(int index) {

}

template <typename T>
T LinkedList<T>::getItem(void) {

}

template <typename T>
int LinkedList<T>::getSize(void) {
    return size;
}

template <typename T>
int LinkedList<T>::indexOf(T item) {

}

template <typename T>
int LinkedList<T>::lastIndexOf(T item) {

}

template <typename T>
bool LinkedList<T>::hasNext(void) {
    return (current->link != NULL);
}

template <typename T>
T LinkedList<T>::next(void) {
    if(!hasNext()) {
        printf("참조할 다음 데이터가 없습니다.\n");
        exit(1);
    }

    previous = current;
    current = current->link;

    return current->data;
}

template <typename T>
T LinkedList<T>::first(void) {
    if(isEmpty()) {
        printf("저장된 데이터가 없습니다.\n");
        exit(1);
    }

    previous = head;
    current = head->link;

    return current->data;
}

#endif /* SinglyLinkedList_hpp */
