#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <algorithm>
using namespace std;

template <typename T>
class LinkedList {
private:
    class Node {
        friend class LinkedList;
    private:
        T data;
        Node* leftLink;
        Node* rightLink;
        
    public:
        Node(void) {
            leftLink = NULL;
            rightLink = NULL;
        }
        Node(T item, Node* previous, Node* next) {
            data = item;
            leftLink = previous;
            rightLink = next;
        }
    };
    
    Node* head;
    Node* tail;
    Node* current;
    int size;
    int (*compare)(const void*, const void*);
    
    bool verifyReferenceScope(int index);
    bool isPossibleToAdd(int index);
    void addToSort(T item);
    Node* getNodeAt(int index);
    
public:
    class iterator {
        friend class LinkedList;
    private:
        Node* current;
        
    public:
        iterator(Node* init = NULL):current(init) {}
        T& operator*(void) const {
            return current->data;
        }
        T* operator->(void) const {
            return current;
        }
        iterator& operator=(const iterator& reference) {
            current = reference.current;
            return *this;
        }
        iterator& operator++(void) {
            current = current->rightLink;
            return *this;
        }
        iterator& operator--(void) {
            current = current->leftLink;
            return *this;
        }
        bool operator==(const iterator& operand) {
            return current == operand.current;
        }
        bool operator!=(const iterator& operand) {
            return current != operand.current;
        }
    };
    
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
    
    iterator begin(void);
    iterator end(void);
    iterator erase(LinkedList<T>::iterator deletePosition);
    
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
    while((search->rightLink != tail) && (compare((void*)&item, (void*)&(search->rightLink->data)) >= 0)) {
        search = search->rightLink;
    }
    
    search->rightLink->leftLink = new Node(item, search, search->rightLink);
    search->rightLink = search->rightLink->leftLink;
    size++;
    return;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getNodeAt(int index) {
    if(index == -1) {
        return head;
    } else if(index == size) {
        return tail;
    }
    
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d] 노드를 참조할 수 없습니다.\n",index);
        exit(EXIT_FAILURE);
    }
    Node* search;
    
    if(2*index - size < 0) {
        search = head;
        for(int i = 0; i <= index; i++) {
            search = search->rightLink;
        }
    } else {
        search = tail;
        for(int i = size - 1; i >= index; i--) {
            search = search->leftLink;
        }
    }
    
    return search;
}

template <typename T>
LinkedList<T>::LinkedList() {
    head = new Node();  // 더미노드 추가
    tail = new Node();
    head->leftLink = NULL;
    head->rightLink = tail;
    tail->leftLink = head;
    tail->rightLink = NULL;
    
    current = head;
    size = 0;
    compare = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy) {
    head = new Node();  // 더미노드 추가
    tail = new Node();
    head->leftLink = NULL;
    head->rightLink = tail;
    tail->leftLink = head;
    tail->rightLink = NULL;
    
    Node* search = copy.head;
    Node* tracking = head;
    
    size = 0;
    while(search->rightLink != copy.tail) {
        search = search->rightLink;
        tracking->rightLink->leftLink = new Node(search->data, tracking, tracking->rightLink);
        tracking->rightLink = tracking->rightLink->leftLink;
        size++;
    }
    current = head;
    compare = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(head->rightLink != NULL) {
        Node* temp = head->rightLink;
        head->rightLink = temp->rightLink;
        delete temp;
    }
    delete head;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& reference) {
    LinkedList<T> temp = reference;
    size = temp.getSize();
    std::swap(temp.head, head);
    std::swap(temp.tail, tail);
    return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty(void) {
    return (head->rightLink == tail);
}

template <typename T>
void LinkedList<T>::add(int index, T item) {
    if(!isPossibleToAdd(index)) {
        fprintf(stderr, "index[%d]에 저장이 불가능합니다.\n", index);
        return;
    }
    
    Node* search = getNodeAt(index - 1);
    search->rightLink->leftLink = new Node(item, search, search->rightLink);
    search->rightLink = search->rightLink->leftLink;
    size++;
    return;
}

template <typename T>
void LinkedList<T>::add(T item) {
    tail->leftLink->rightLink = new Node(item, tail->leftLink, tail);
    tail->leftLink = tail->leftLink->rightLink;
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
    
    Node* target = getNodeAt(index);
    T deletedData = target->data;
    
    target->leftLink->rightLink = target->rightLink;
    target->rightLink->leftLink = target->leftLink;
    
    
    if(target == current) {
        current = target->leftLink;
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
    
    Node* target = current;
    T deletedData = target->data;
    
    target->leftLink->rightLink = target->rightLink;
    target->rightLink->leftLink = target->leftLink;
    
    current = target->leftLink;
    
    delete target;
    
    size--;
    return deletedData;
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
    
    while(search->rightLink != tail) {
        search = search->rightLink;
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
    
    while(search->rightLink != tail) {
        search = search->rightLink;
        if(search->data == item) {
            result = index;
        }
        index++;
    }
    
    return result;
}

template <typename T>
bool LinkedList<T>::hasNext(void) {
    return (current->rightLink != NULL);
}

template <typename T>
T LinkedList<T>::next(void) {
    if(!hasNext()) {
        fprintf(stderr, "참조할 다음 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    current = current->rightLink;
    
    return current->data;
}

template <typename T>
T LinkedList<T>::first(void) {
    if(isEmpty()) {
        fprintf(stderr, "저장된 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    
    current = head->rightLink;
    
    return current->data;
}

template <typename T>
void LinkedList<T>::sort(int (*compare)(const void *, const void *)) {
    LinkedList temp;
    //    this->compare = compare;
    temp.compare = compare;
    
    Node* search = head;
    while(search->rightLink != tail) {
        search = search->rightLink;
        temp.addToSort(search->data);
    }
    
    std::swap(temp.head, head);
    std::swap(temp.tail, tail);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin(void) {
    return iterator(head->rightLink);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end(void) {
    return iterator(tail);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(LinkedList<T>::iterator deletePosition) {
    if(deletePosition.current == NULL) {
        fprintf(stderr, "begin(), end()를 통해 참조 위치를 설정하세요");
        exit(EXIT_FAILURE);
    }
    
    iterator next((deletePosition.current)->rightLink);
    Node* target = deletePosition.current;
    
    target->leftLink->rightLink = target->rightLink;
    target->rightLink->leftLink = target->leftLink;
    
    delete target;
    
    size--;
    return next;
}


#endif /* DoublyLinkedList_hpp */
