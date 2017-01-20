#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <algorithm>
using namespace std;

template <typename E>
class LinkedList {
private:
    class Node {
        friend class LinkedList;
    private:
        E data;
        Node* leftLink;
        Node* rightLink;
        
    public:
        Node(void) {
            leftLink = NULL;
            rightLink = NULL;
        }
        Node(E item, Node* previous, Node* next) {
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
    void addToSort(E item);
    Node* getNodeAt(int index);
    
public:
    class iterator {
        friend class LinkedList;
    private:
        Node* current;
        
    public:
        iterator(Node* init = NULL):current(init) {}
        E& operator*(void) const {
            return current->data;
        }
        E* operator->(void) const {
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
    LinkedList(const LinkedList<E>& copy);
    ~LinkedList();
    LinkedList<E>& operator=(const LinkedList<E>& reference);
    
    bool isEmpty(void);
    void add(E item);
    void add(int index, E item);
    void set(int index, E item);
    E remove(int index);
    E remove(void);
    E getItem(int index);
    E getItem(void);
    int getSize(void);
    int indexOf(E item);
    int lastIndexOf(E item);
    
    bool hasNext(void);
    E first(void);
    E next(void);
    void sort(int (*compare)(const void *, const void *));
    
    iterator begin(void);
    iterator end(void);
    iterator erase(LinkedList<E>::iterator deletePosition);
    
};

template <typename E>
bool LinkedList<E>::verifyReferenceScope(int index) {
    return (index >= 0) && (index < size);
}

template <typename E>
bool LinkedList<E>::isPossibleToAdd(int index) {
    return ((index >= 0) && (index <= size));
}

template <typename E>
void LinkedList<E>::addToSort(E item) {
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

template <typename E>
typename LinkedList<E>::Node* LinkedList<E>::getNodeAt(int index) {
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

template <typename E>
LinkedList<E>::LinkedList() {
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

template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E>& copy) {
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

template <typename E>
LinkedList<E>::~LinkedList() {
    while(head->rightLink != NULL) {
        Node* temp = head->rightLink;
        head->rightLink = temp->rightLink;
        delete temp;
    }
    delete head;
}

template <typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E>& reference) {
    LinkedList<E> temp = reference;
    size = temp.getSize();
    std::swap(temp.head, head);
    std::swap(temp.tail, tail);
    return *this;
}

template <typename E>
bool LinkedList<E>::isEmpty(void) {
    return (head->rightLink == tail);
}

template <typename E>
void LinkedList<E>::add(int index, E item) {
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

template <typename E>
void LinkedList<E>::add(E item) {
    tail->leftLink->rightLink = new Node(item, tail->leftLink, tail);
    tail->leftLink = tail->leftLink->rightLink;
    size++;
    return;
}

template <typename E>
void LinkedList<E>::set(int index, E item) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d]의 값을 변경할 수 없습니다.\n", index);
        return;
    }
    
    Node* search = getNodeAt(index);
    search->data = item;
    return;
}

template <typename E>
E LinkedList<E>::remove(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d]의 값을 삭제할 수 없습니다.\n", index);
        exit(EXIT_FAILURE);
    }
    
    Node* target = getNodeAt(index);
    E deletedData = target->data;
    
    target->leftLink->rightLink = target->rightLink;
    target->rightLink->leftLink = target->leftLink;
    
    
    if(target == current) {
        current = target->leftLink;
    }
    
    delete target;
    
    size--;
    return deletedData;
}

template <typename E>
E LinkedList<E>::remove(void) {
    if(current == head) {
        fprintf(stderr, "first(), next()를 통해 참조 위치를 설정하세요");
        exit(EXIT_FAILURE);
    }
    
    Node* target = current;
    E deletedData = target->data;
    
    target->leftLink->rightLink = target->rightLink;
    target->rightLink->leftLink = target->leftLink;
    
    current = target->leftLink;
    
    delete target;
    
    size--;
    return deletedData;
}

template <typename E>
E LinkedList<E>::getItem(int index) {
    Node* search = getNodeAt(index);
    return search->data;
}

template <typename E>
E LinkedList<E>::getItem(void) {
    return current->data;
}

template <typename E>
int LinkedList<E>::getSize(void) {
    return size;
}

template <typename E>
int LinkedList<E>::indexOf(E item) {
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

template <typename E>
int LinkedList<E>::lastIndexOf(E item) {
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

template <typename E>
bool LinkedList<E>::hasNext(void) {
    return (current->rightLink != NULL);
}

template <typename E>
E LinkedList<E>::next(void) {
    if(!hasNext()) {
        fprintf(stderr, "참조할 다음 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    current = current->rightLink;
    
    return current->data;
}

template <typename E>
E LinkedList<E>::first(void) {
    if(isEmpty()) {
        fprintf(stderr, "저장된 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    
    current = head->rightLink;
    
    return current->data;
}

template <typename E>
void LinkedList<E>::sort(int (*compare)(const void *, const void *)) {
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

template <typename E>
typename LinkedList<E>::iterator LinkedList<E>::begin(void) {
    return iterator(head->rightLink);
}

template <typename E>
typename LinkedList<E>::iterator LinkedList<E>::end(void) {
    return iterator(tail);
}

template <typename E>
typename LinkedList<E>::iterator LinkedList<E>::erase(LinkedList<E>::iterator deletePosition) {
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
