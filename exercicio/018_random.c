#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    srand(time(0));

    int number1 = (rand() % 20) + 1;
    int number2 = (rand() % 20) + 1;
    int number3 = (rand() % 20) + 1;

    printf("%d ", number1);
    printf("%d ", number2);
    printf("%d ", number3);

    return 0;
}
