//
//  DequeADT.cpp
//  DataStructure
//
//  Created by sogoagain on 2017. 2. 1..
//

#include <stdio.h>
#include <iostream>
#include "ListBaseDeque/ListBaseDeque.hpp"

using namespace std;

int main(int argc, char** argv) {
    Deque<int> deque1, deque2;
    
    srand(time(NULL));
    
    printf("----------deque1 addFirst----------\n");
    for(int i = 0; i < 10; i++) {
        int item = rand()%10;
        deque1.addFirst(item);
        printf("%d ", item);
    }
    printf("\n--------------------------------\n");
    
    printf("----------deque1 getFirst----------\n");
    printf("%d ", deque1.getFirst());
    printf("\n--------------------------------\n");
    
    printf("----------deque2=deque1----------\n");
    deque2 = deque1;
    printf("--------------------------------\n");
    
    printf("----------deque1 removeFirst----------\n");
    while(!deque1.isEmpty()) {
        printf("%d ", deque1.removeFirst());
    }
    printf("\n--------------------------------\n");
    
    printf("----------deque2 removeFirst----------\n");
    while(!deque2.isEmpty()) {
        printf("%d ", deque2.removeFirst());
    }
    printf("\n--------------------------------\n");
    
    printf("----------deque1 addLast----------\n");
    for(int i = 0; i < 10; i++) {
        int item = rand()%10;
        deque1.addLast(item);
        printf("%d ", item);
    }
    printf("\n--------------------------------\n");
    
    printf("----------deque1 getLast----------\n");
    printf("%d ", deque1.getLast());
    printf("\n--------------------------------\n");
    
    printf("----------deque1 removeLast----------\n");
    while(!deque1.isEmpty()) {
        printf("%d ", deque1.removeLast());
    }
    printf("\n--------------------------------\n");
}
