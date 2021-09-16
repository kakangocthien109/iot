#include <stdio.h>

int main()
{
    int a;

    printf("Xin vui long nhap so a:\n");
    scanf("%d", &a);

    printf("Cac so chan co tu 1 den %d la: ", a);

    for (int i = 0; i < a; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }

return 0;
}