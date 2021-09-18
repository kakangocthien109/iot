#include <stdio.h>
int main()
{
    int a, b, temp;
    printf("Xin vui long nhap so dau tien: ");
    scanf("%d", &a);
    printf("Xin vui long nhap so thu hai: ");
    scanf("%d", &b);

    int *c = &a;
    int *d = &b;

    temp = *c;
    *c = *d;
    *d = temp;

    printf("2 so sau khi bi hoan doi la %d va %d\n", *c, *d);
    return 0;
}
