#include <stdio.h>
#include <stdlib.h>
//#include "SinglyLinkedList/SinglyLinkedList.hpp"
#include "CircularLinkedList/CircularLinkedList.hpp"
using namespace std;

//typedef ArrayList<int> List;
typedef LinkedList<int> List;

int compare(const void* previous , const void* after) {
    if(*(int*)previous > *(int*)after) {
        return -1;
    } else if(*(int*)previous == *(int*)after) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    List list1, list2;
    printf("list1.isEmpty(): %s\n", list1.isEmpty() ? "TRUE" : "FALSE");

    printf("list1.add()\n");
    srand(time(NULL));
    for(int i=0; i<9; i++) {
        list1.add(rand()%10);
    }
    list1.add(123);

    // 데이터 출력
    printf("print list1\n");
    printf("list1.getSize(): %d\n", list1.getSize());

    printf("%d ", list1.first());
    for(int i = 0; i<list1.getSize()-1; i++) {
         printf("%d ", list1.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");
    
    printf("list2.add()\n");
    for(int i=0; i<3; i++) {
        list2.add(rand()%10);
    }
    
    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());
    
    printf("%d ", list2.first());
    for(int i = 0; i < list2.getSize()-1; i++) {
        printf("%d ", list2.next());
    }
    printf("\n");
    printf("---printf finished--\n");
    
    printf("list2 = list1\n");
    list2 = list1;
    
    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());

    printf("%d ", list2.first());
    for(int i = 0; i < list2.getSize()-1; i++) {
         printf("%d ", list2.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("list2.add(0, 14)\n");
    list2.add(0, 14);
    printf("list2.add(3, 20)\n");
    list2.add(3, 20);
    printf("list2.add(list2.getSize(), 99)\n");
    list2.add(list2.getSize(), 99);
    printf("list2.set(1, 12)\n");
    list2.set(1, 12);
    printf("list2,set(2, 99)\n");
    list2.set(2, 99);

    // 데이터 출력
    printf("print list2\n");
    printf("list2.getSize(): %d\n", list2.getSize());

    printf("%d ", list2.first());
    for(int i = 0; i < list2.getSize()-1; i++) {
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
    for(int i = 0; i < list2.getSize()-1; i++) {
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
    for(int i = 0; i < list3.getSize()-1; i++) {
        printf("%d ", list3.getItem(i));
    }
    printf("\n");

    printf("list3.sort()\n");
    list3.sort(compare);

    printf("list3 print\n");
    printf("%d ", list3.first());
    for(int i = 0; i < list3.getSize()-1; i++) {
         printf("%d ", list3.next());
    }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("List list4 = list1\n");
    List list4 = list1;
    printf("list4.sort(compare)\n");

    printf("list4 print\n");
    printf("%d ", list4.first());
    for(int i = 0; i < list4.getSize()*2; i++) {
         printf("%d ", list4.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");
    
    return 0;
}
