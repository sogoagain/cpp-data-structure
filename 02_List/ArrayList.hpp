#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
    private:
        const static int MAX_SIZE=100;
        T* storage;
        int currentPosition;
        int size;

        bool isEmpty(void);
        bool isFull(void);
        bool checkIndex(int index);

    public:
        ArrayList();
        void add(T item);
        void add(int index, T item);
        void set(int index, T item);
        T remove(int index);
        T remove(void);
        T getItem(int index);
        int getSize(void);
        int indexOf(T item);
        bool hasNext(void);
        T first(void);
        T next(void);
        int getCurrentPosition(void);
        ~ArrayList();
};

template <typename T>
ArrayList<T>::ArrayList() {
    storage = new T[MAX_SIZE];
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
    return size == MAX_SIZE;
}

template <typename T>
bool ArrayList<T>::checkIndex(int index) {
    return (size >= 0) && (index <= size);
}

template <typename T>
void ArrayList<T>::add(int index, T item) {
    if(isFull() || !checkIndex(index)) {
        printf("저장이 불가능합니다.\n");
        return;
    }
    
    for(int i = size - 1; i >= index; i--) {
        storage[i+1] = storage[i];
    }
    
    storage[index] = item;
    currentPosition = index;
    size++;
    return;
}

template <typename T>
void ArrayList<T>::add(T item) {
    return add(size, item);
}

template <typename T>
void ArrayList<T>::set(int index, T item) {
    if(!checkIndex(index) || index == size) {
        printf("값을 변경할 수 없습니다.\n");
        return;
    }
    
    storage[index] = item;
    currentPosition = index;
    return;
}

template <typename T>
T ArrayList<T>::remove(int index) {
    if(!checkIndex(index) || index == size) {
        fprintf(stderr, "잘못된 위치를 참조하여 삭제에 실패했습니다.\n");
        exit(1);
    }
    
    T target = storage[index];
    for(int i = index; i < size; i++) {
        storage[i] = storage[i+1];
    }
    
    currentPosition = index - 1;
    size--;
    return target;
}

template <typename T>
T ArrayList<T>::remove(void) {
    return remove(currentPosition);
}

template <typename T>
T ArrayList<T>::getItem(int index) {
    if(!checkIndex(index) || index == size) {
        fprintf(stderr, "잘못된 위치를 참조하여 값을 가져올 수 없습니다.");
        exit(1);
    }
    
    currentPosition = index;
    return storage[index];
}

template <typename T>
int ArrayList<T>::getSize(void) {
    return size;
}

template <typename T>
int ArrayList<T>::indexOf(T item) {
    for(int i = 0; i < size; i++) {
        if(storage[i] == item) {
            currentPosition = i;
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

template <typename T>
int ArrayList<T>::getCurrentPosition(void) {
    return currentPosition;
}

#endif /* ArrayList_hpp */
