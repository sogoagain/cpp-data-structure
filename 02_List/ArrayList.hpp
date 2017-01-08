#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
    private:
        int maxSize;
        T* storage;
        int currentPosition;
        int size;
    
        bool verifyReferenceScope(int index);
        bool isPossibleToAdd(int index);

    public:
        ArrayList();
        ArrayList(int maxSize);
        bool isEmpty(void);
        bool isFull(void);
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
        ~ArrayList();
};

template <typename T>
bool ArrayList<T>::verifyReferenceScope(int index) {
    return (index >= 0) && (index < size);
}

template <typename T>
bool ArrayList<T>::isPossibleToAdd(int index) {
    return !isFull() && ((size >= 0) && (index <= size));
}

template <typename T>
ArrayList<T>::ArrayList() {
    maxSize = 100;
    storage = new T[maxSize];
    size = 0;
    currentPosition = -1;
}

template <typename T>
ArrayList<T>::ArrayList(int maxSize) {
    this->maxSize = maxSize;
    storage = new T[maxSize];
    size = 0;
    currentPosition = -1;
}


template <typename T>
ArrayList<T>::~ArrayList() {
    delete []storage;
}

template <typename T>
bool ArrayList<T>::isEmpty(void) {
    return size == 0;
}

template <typename T>
bool ArrayList<T>::isFull(void) {
    return size == maxSize;
}

template <typename T>
void ArrayList<T>::add(int index, T item) {
    if(!isPossibleToAdd(index)) {
        printf("저장이 불가능합니다.\n");
        return;
    }
    
    for(int i = size - 1; i >= index; i--) {
        storage[i+1] = storage[i];
    }
    
    storage[index] = item;
    size++;
    return;
}

template <typename T>
void ArrayList<T>::add(T item) {
    return add(size, item);
}

template <typename T>
void ArrayList<T>::set(int index, T item) {
    if(!verifyReferenceScope(index)) {
        printf("값을 변경할 수 없습니다.\n");
        return;
    }
    
    storage[index] = item;
    return;
}

template <typename T>
T ArrayList<T>::remove(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "잘못된 위치를 참조하여 삭제에 실패했습니다.\n");
        exit(1);
    }
    
    T target = storage[index];
    for(int i = index; i < size; i++) {
        storage[i] = storage[i+1];
    }
    
    if(index < currentPosition || index == size - 1) {
        currentPosition--;
    }
    size--;
    return target;
}

template <typename T>
T ArrayList<T>::remove(void) {
    return remove(currentPosition);
}

template <typename T>
T ArrayList<T>::getItem(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "잘못된 위치를 참조하여 값을 가져올 수 없습니다.");
        exit(1);
    }
    
    return storage[index];
}

template <typename T>
T ArrayList<T>::getItem(void) {
    return getItem(currentPosition);
}

template <typename T>
int ArrayList<T>::getSize(void) {
    return size;
}

template <typename T>
int ArrayList<T>::indexOf(T item) {
    for(int i = 0; i < size; i++) {
        if(storage[i] == item) {
            return i;
        }
    }
    
    return -1;
}

template <typename T>
int ArrayList<T>::lastIndexOf(T item) {
    for(int i = size - 1; i >= 0; i--) {
        if(storage[i] == item) {
            return i;
        }
    }
    
    return -1;
}

template <typename T>
bool ArrayList<T>::hasNext(void) {
    return currentPosition < size - 1;
}

template <typename T>
T ArrayList<T>::next(void) {
    if(!hasNext()) {
        fprintf(stderr, "리스트에 다음 항목이 없습니다.\n");
        exit(1);
    }
    
    currentPosition++;
    return storage[currentPosition];
}

template <typename T>
T ArrayList<T>::first(void) {
    if(isEmpty()) {
        fprintf(stderr, "리스트가 공백 상태입니다.\n");
        exit(1);
    }
    
    currentPosition = 0;
    return storage[currentPosition];
}

#endif /* ArrayList_hpp */
