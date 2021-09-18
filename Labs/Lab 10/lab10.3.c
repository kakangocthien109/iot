#include <stdio.h>
int main()
{
    int a, b;
    printf("Xin vui long nhap so dau tien: ");
    scanf("%d", &a);
    printf("Xin vui long nhap so thu hai: ");
    scanf("%d", &b);

    int *c = &a;
    int *d = &b;

    if (*c > *d)
    {
        printf("So %d lon hon so %d\n", *c, *d);
    }
    
    else if (*c == *d)
    {
        printf("Hai so %d va %d bang nhau\n", *c, *d);
    }

    else if (*c < *d)
    {
        printf("So %d nho hon so %d\n", *c, *d);
    }
    return 0;
}
