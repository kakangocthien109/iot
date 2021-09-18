#include <stdio.h>

int main() {
    int d = 10;
    float e = 20;
    char f = 'h';

    int *a = &d;
    float *b = &e;
    char *c = &f;

    printf("%d\n", *a);
    printf("%g\n", *b);
    printf("%c\n", *c);
    
    return 0;
}