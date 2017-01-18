#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
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
        int (*compare)(const void*, const void*);

        bool verifyReferenceScope(int index);
        bool isPossibleToAdd(int index);
        void addToSort(T item);
        Node* getNodeAt(int index)  {
            if(index == -1) {
                return head;
            }

            if(!verifyReferenceScope(index)) {
                fprintf(stderr, "index[%d] 노드를 참조할 수 없습니다.\n",index);
                exit(EXIT_FAILURE);
            }
        
            Node* search = head;
            for(int i = 0; i <= index; i++) {
                search = search->link;
            }
            return search;
        }

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
        void sort(int (*compare)(const void *, const void *));
};

template <typename T>
bool LinkedList<T>::verifyReferenceScope(int index) {
    return (index >= 0) && (index < size);
}

template <typename T>
bool LinkedList<T>::isPossibleToAdd(int index) {
    return ((index >= 0) && (index <= size));
}

template <typename T>
void LinkedList<T>::addToSort(T item) {
    if(compare == NULL) {
        fprintf(stderr, "비교 함수가 등록되지 않아 정렬을 중단합니다.\n");
        exit(EXIT_FAILURE);
    }

    Node* search = head;
    while((search->link != NULL) && (compare((void*)&item, (void*)&(search->link->data)) >= 0)) {
        search = search->link; 
    }
    search->link = new Node(item, search->link);
    size++;
    return;
}

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
    Node* tail;
    Node* search;

    head = new Node();  // 더미노드 추가
    tail = head;
    search = copy.head;
    size = 0;

    while(search->link != NULL) {
        search = search->link;
        tail->link = new Node(search->data, NULL);
        tail = tail->link;
        size++;
    }

    current = head;
    previous = NULL;
    compare = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(head->link != NULL) {
        Node* temp = head->link;
        head->link = temp->link;
        delete temp;
    }
    delete head;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& reference) {
    LinkedList<T> temp = reference;
    size = temp.getSize();
    std::swap(temp.head, head);
    return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty(void) {
    return (head->link == NULL);
}

template <typename T>
void LinkedList<T>::add(int index, T item) {
    if(!isPossibleToAdd(index)) {
        fprintf(stderr, "index[%d]에 저장이 불가능합니다.\n", index);
       return;
    }

    Node* search = getNodeAt(index - 1);
    search->link = new Node(item, search->link);
    size++;
    return;
}

template <typename T>
void LinkedList<T>::add(T item) {
    head->link = new Node(item, head->link);
    size++;
    return;
}

template <typename T>
void LinkedList<T>::set(int index, T item) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d]의 값을 변경할 수 없습니다.\n", index);
       return;
    }

    Node* search = getNodeAt(index);
    search->data = item;
    return;
}

template <typename T>
T LinkedList<T>::remove(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d]의 값을 삭제할 수 없습니다.\n", index);
        exit(EXIT_FAILURE);
    }

    Node* search = getNodeAt(index - 1);
    Node* target = search->link;
    T deletedData;

    deletedData = target->data;
    search->link = target->link;

    if(target == current) {
        current = search;
    }
    
    delete target;

    size--;
    return deletedData;
}

template <typename T>
T LinkedList<T>::remove(void) {
    if(current == head) {
        fprintf(stderr, "first(), next()를 통해 참조 위치를 설정하세요");
        exit(EXIT_FAILURE);
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
    Node* search = getNodeAt(index);
    return search->data;
}

template <typename T>
T LinkedList<T>::getItem(void) {
    return current->data;
}

template <typename T>
int LinkedList<T>::getSize(void) {
    return size;
}

template <typename T>
int LinkedList<T>::indexOf(T item) {
    int index = 0;
    Node* search = head;

    while(search->link != NULL) {
        search = search->link;
        if(search->data == item) {
            return index;
        }
        index++;
    }
    return -1;
}

template <typename T>
int LinkedList<T>::lastIndexOf(T item) {
    int index = 0;
    int result = -1;
    Node* search = head;

    while(search->link != NULL) {
        search = search->link;
        if(search->data == item) {
            result = index;
        }
        index++;
    }

    return result;
}

template <typename T>
bool LinkedList<T>::hasNext(void) {
    return (current->link != NULL);
}

template <typename T>
T LinkedList<T>::next(void) {
    if(!hasNext()) {
        fprintf(stderr, "참조할 다음 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }

    previous = current;
    current = current->link;

    return current->data;
}

template <typename T>
T LinkedList<T>::first(void) {
    if(isEmpty()) {
        fprintf(stderr, "저장된 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }

    previous = head;
    current = head->link;

    return current->data;
}

template <typename T>
void LinkedList<T>::sort(int (*compare)(const void *, const void *)) {
    LinkedList temp;
//    this->compare = compare;
    temp.compare = compare;
    
    Node* search = head;
    while(search->link != NULL) {
        search = search->link;
        temp.addToSort(search->data); 
    }

    std::swap(temp.head, head);
}

#endif /* SinglyLinkedList_hpp */
