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

    int e = *c + *d;

    printf("Tong 2 so %d va %d la %d\n", *c, *d, e);
    return 0;
}
