#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList/DoublyLinkedList.hpp"

using namespace std;

typedef LinkedList<int> List;

int main(int argc, char** argv) {
    List list;

    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        list.add(rand()%3);
    }
    
    for(List::iterator i = list.begin(); i != list.end(); ++i) {
        printf("%d ", *i);
    }
    printf("\n---------------\n\n");

    int target = rand()%3;
    printf("삭제대상: %d\n", target);

    for(List::iterator i = list.begin(); i != list.end();) {
        if(*i == target) {
            i = list.erase(i);
        }
        else {
            ++i;
        }
    }

    for(List::iterator i = list.begin(); i != list.end(); ++i) {
        printf("%d ", *i);
    }
    printf("\n---------------\n\n");
    return 0;
}
