#include <stdio.h>
#include <string.h>

void search(int *x, int *y)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (*(x + i) == *y)
        {
            printf("Da tim thay phan tu.\n");
            return;
        }
    }
    printf("Khong tim thay phan tu.\n");
}

int main()
{
    int array[5];
    int *pnt1 = array;
    int *pnt2;

    for (int p = 0; p < 5; p++)
    {
        printf("Xin vui long nhap phan tu thu %d: ", p);
        scanf("%d", (pnt1 + p));
    }

    printf("Xin vui long nhap phan tu can tim kiem: ");
    scanf("%d", pnt2);

    search(pnt1, pnt2);

    return 0;
}