#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int a;
    printf("Xin vui long nhap a\n");
    scanf("%d", &a);
    if (a % 2 == 0)  {
        printf("a la so chan\n");
    }
    else {
        printf("a la so le");
    }

    return 0;
}