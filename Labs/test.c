#include <stdio.h>
#include <stdlib.h>
int main()
{
    int b = 10;
    int *a = &b;

    malloc(*a, sizeof(int));

    return 0;
}