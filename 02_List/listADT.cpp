#include <stdio.h>
#include <stdlib.h>
#include "ArrayList/ArrayList.hpp"
#include "SinglyLinkedList/SinglyLinkedList.hpp"
using namespace std;

//typedef ArrayList<int> List;
typedef LinkedList<int> List;

int main() {
    List list1, list2;
    printf("list1.isEmpty(): %s\n", list1.isEmpty() ? "TRUE" : "FALSE");

    printf("list1.add()\n");
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        list1.add(rand()%3);
    }

    // 데이터 출력
    printf("print list1\n");
    printf("list1.getSize(): %d\n", list1.getSize());

    printf("%d ", list1.first());
     while(list1.hasNext()) {
         printf("%d ", list1.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");
    
    printf("list2 = list1\n");
    list2 = list1;
    
    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());

    printf("%d ", list2.first());
     while(list2.hasNext()) {
         printf("%d ", list2.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("list2.add(9, 99)\n");
    list2.add(9, 99);
    printf("list2.set(1, 12)\n");
    list2.set(1, 12);
    printf("list2,set(2, 99)\n");
    list2.set(2, 99);

    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());

    printf("%d ", list2.first());
     while(list2.hasNext()) {
         printf("%d ", list2.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("searching...\n");
    printf("%d ", list2.first());
    for(int i = 0; i < 4; i++) {
       printf("%d ", list2.next());
    }
    printf("\n");
    printf("list2.remove(): %d\n",list2.remove());
    printf("list2.remove(1): %d\n", list2.remove(1));
    printf("list2.getItem(): %d\n", list2.getItem());

    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());

    printf("%d ", list2.first());
     while(list2.hasNext()) {
         printf("%d ", list2.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("list2.indexOf(99): %d\n", list2.indexOf(99));
    printf("list2.lastIndexOf(99): %d\n", list2.lastIndexOf(99));

    printf("List list3 = list2\n");
    List list3 = list2;

    printf("list3.getSize(): %d\n", list3.getSize());
    printf("list3.getItem()\n");
    for(int i = 0; i < list2.getSize(); i++) {
        printf("%d ", list2.getItem(i));
    }
    printf("\n");
    return 0;
}
