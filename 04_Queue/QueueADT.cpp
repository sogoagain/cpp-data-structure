//
//  QueueADT.cpp
//  DataStructure
//
//  Created by sogoagain on 2017. 1. 25..
//

#include <stdio.h>
#include <iostream>
//#include "CircularQueue/CircularQueue.hpp"
#include "ListBaseQueue/ListBaseQueue.hpp"

using namespace std;

int main(int argc, char** argv) {
    Queue<int> queue1, queue2;
    
    srand(time(NULL));
    
    printf("----------queue1 offer----------\n");
    for(int i = 0; i < 10; i++) {
        int item = rand()%10;
        queue1.offer(item);
        printf("%d ", item);
    }
    printf("\n--------------------------------\n");
    
    printf("----------queue1 peek----------\n");
    printf("%d ", queue1.peek());
    printf("\n--------------------------------\n");
    
    printf("----------queue2=queue1----------\n");
    queue2 = queue1;
    printf("--------------------------------\n");
    
    printf("----------queue1 poll----------\n");
    while(!queue1.isEmpty()) {
        printf("%d ", queue1.poll());
    }
    printf("\n--------------------------------\n");
    
    printf("----------queue2 poll----------\n");
    while(!queue2.isEmpty()) {
        printf("%d ", queue2.poll());
    }
    printf("\n--------------------------------\n");
}
