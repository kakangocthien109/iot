#include<stdio.h>

int main() {
    const int b = 10;
    int *a = &b;

    *a = 20;

    printf("%d\n", b);
    return 0;
}