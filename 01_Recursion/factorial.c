#include <stdio.h>
#include <stdlib.h>

int factorial(int number) {
    if(number == 1)
        return 1;
    else
        return number * factorial(number - 1);
}

int main(int argc, char** argv) {
    int number;

    if(argc != 2) {
        printf("Usage: %s [NUMBER]\n", argv[0]);
        return -1;
    } else {
       number = atoi(argv[1]); 
    }

    printf("%d! = %d\n", number, factorial(number));
    return 0;
}
