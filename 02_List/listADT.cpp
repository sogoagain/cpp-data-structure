#include <stdio.h>
#include <stdlib.h>
#include "ArrayList/ArrayList.hpp"
#include "SinglyLinkedList/SinglyLinkedList.hpp"
using namespace std;

// typedef ArrayList<int> List;
typedef LinkedList<int> List;

int main() {
    List list1, list2, list3;

    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        list1.add(rand()%3);
    }

    /* 데이터 출력 */
    printf("list1\n");
    printf("현재 데이터 수: %d\n", list1.getSize());

    printf("%d ", list1.first());
     while(list1.hasNext()) {
         printf("%d ", list1.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    list2 = list1;

    printf("list2\n");
    printf("현재 데이터 수: %d\n", list2.getSize());

    printf("%d ", list2.first());
     while(list2.hasNext()) {
         printf("%d ", list2.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("list1 9번째 위치에 99 저장\n");
    list1.add(9, 99);
    printf("list1\n");
    printf("현재 데이터 수: %d\n", list1.getSize());

    printf("%d ", list1.first());
     while(list1.hasNext()) {
         printf("%d ", list1.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");

    printf("list1 4번째 위치값 123으로 변경\n");
    list1.set(4, 123);
    printf("list1\n");
    printf("현재 데이터 수: %d\n", list1.getSize());

    printf("%d ", list1.first());
     while(list1.hasNext()) {
         printf("%d ", list1.next());
     }
    printf("\n"); 
    printf("---printf finished--\n");


    printf("list1 4번째 값 삭제\n");
    list1.first();
    list1.next();
    list1.next();
    list1.next();
    printf("4번째 값: %d\n", list1.next());
    printf("삭제된 값: %d\n",list1.remove(4));
    printf("list1의 5번째 값: %d\n", list1.getItem(5));
    printf("현재 탐색 중인 위치의 값: %d\n", list1.getItem());
    printf("99의 위치: %d\n", list1.indexOf(99));

    return 0;
}
