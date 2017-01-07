#include <stdio.h>
#include <stdlib.h>

void hanoi(int number, char from, char by, char to) {
    if (number == 1) {
        printf("1번 원판을 %c에서 %c로 옮깁니다.\n", from, to);
        return;
    } else {
        hanoi(number - 1, from, to, by);
        printf("%d번 원판을 %c에서 %c로 옮깁니다.\n", number, from, to);
        hanoi(number - 1, by, from, to);
    }
}

int main(int argc, char** argv) {
    int numberOfDisks;

    if(argc != 2) {
        printf("Usage: %s [Number]\n", argv[0]);
        return -1;
    } else {
        numberOfDisks = atoi(argv[1]);
    }

    hanoi(numberOfDisks, 'A', 'B', 'C');

    return 0;
}
