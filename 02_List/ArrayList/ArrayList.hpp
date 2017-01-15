#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
    private:
        int maxSize;
        T* storage;
        int currentPosition;
        int size;
        int (*compare)(const void*, const void*);
    
        bool verifyReferenceScope(int index);
        bool isPossibleToAdd(int index);
        bool isFull(void);

    public:
        ArrayList();
        ArrayList(int maxSize);
        ArrayList(const ArrayList<T>& copy);
        ~ArrayList();
        ArrayList<T>& operator=(const ArrayList<T>& reference);

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
bool ArrayList<T>::verifyReferenceScope(int index) {
    return (index >= 0) && (index < size);
}

template <typename T>
bool ArrayList<T>::isPossibleToAdd(int index) {
    return !isFull() && ((index >= 0) && (index <= size));
}

template <typename T>
bool ArrayList<T>::isFull(void) {
    return size == maxSize;
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
ArrayList<T>::ArrayList(const ArrayList<T>& copy) {
    maxSize = copy.maxSize;
    storage = new T[maxSize];
    size = copy.size;
    currentPosition = -1;

    for(int i = 0; i < size; i++) {
        storage[i] = copy.storage[i];
    }
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete []storage;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& reference) {
    ArrayList temp = reference;
    std::swap(temp.storage, storage);
    maxSize = reference.maxSize;
    size = reference.size;
    currentPosition = -1;

    return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty(void) {
    return size == 0;
}

template <typename T>
void ArrayList<T>::add(int index, T item) {
    if(!isPossibleToAdd(index)) {
        fprintf(stderr, "index[%d]에 저장이 불가능합니다.\n", index);
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
        fprintf(stderr, "index[%d]의 값을 변경할 수 없습니다.\n", index);
        return;
    }
    
    storage[index] = item;
    return;
}

template <typename T>
T ArrayList<T>::remove(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "index[%d]의 값을 삭제할 수 없습니다.\n", index);
        exit(EXIT_FAILURE);
    }
    
    T target = storage[index];
    for(int i = index; i < size; i++) {
        storage[i] = storage[i+1];
    }
    
    if(index <= currentPosition) {
        currentPosition--;
    }
    size--;
    return target;
}

template <typename T>
T ArrayList<T>::remove(void) {
    if(currentPosition == -1) {
        fprintf(stderr, "first(), next()를 통해 참조 위치를 설정하세요");
        exit(EXIT_FAILURE);
    }
    return remove(currentPosition);
}

template <typename T>
T ArrayList<T>::getItem(int index) {
    if(!verifyReferenceScope(index)) {
        fprintf(stderr, "잘못된 위치를 참조하여 값을 가져올 수 없습니다.");
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "참조할 다음 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    
    currentPosition++;
    return storage[currentPosition];
}

template <typename T>
T ArrayList<T>::first(void) {
    if(isEmpty()) {
        fprintf(stderr, "저장된 데이터가 없습니다.\n");
        exit(EXIT_FAILURE);
    }
    
    currentPosition = 0;
    return storage[currentPosition];
}

template <typename T>
void ArrayList<T>::sort(int (*compare)(const void *, const void *)) {
    this->compare = compare; 
    qsort(storage, size, sizeof(T), this->compare);
}

#endif /* ArrayList_hpp */
