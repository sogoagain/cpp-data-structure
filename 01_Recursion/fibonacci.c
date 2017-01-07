#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

int main(int argc, char** argv) {
    int i;
    int NumberOfItems;

    if(argc != 2) {
        printf("Usage: %s [Number of items]\n", argv[0]);
        return -1;
    } else {
        NumberOfItems = atoi(argv[1]);
    }

    for(int i = 0; i < NumberOfItems; i++) {
        printf("%d ", fibonacci(i));
    } 

    printf("finished\n");

    return 0;
}
