#include <stdio.h>

int add(int *pnum1, int *pnum2)
{
        int c = *pnum1 + *pnum2;
        return c;
}

int main()
{
    int a = 3, b = 8;
    int *pnum1 = &a, *pnum2 = &b;
    printf("Tong 2 so la: %d", add(pnum1, pnum2));
    return 0;
}