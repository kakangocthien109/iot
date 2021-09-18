#include <stdio.h>
#include <string.h>

int main()
{
    // int i, j, n;
    // printf("Xin vui long nhap so luong chuoi ky tu");
    // scanf("%d", &n);
    // char name[n][30];
    // char temp[30];

    // for (i = 0; i < n; i++)
    // {
    //     printf("Xin vui long nhap mang: ");
    //     scanf("%s", name[n]);
    // }

    // for (i = 1; i <= n; i++)
    // {
    //     for (j = 0; j <= n - i; j++)
    //     {
    //         if (strcmp(name[j], name[j + 1]) > 0)
    //         {
    //             strcpy(temp, name[j]);
    //             strcpy(name[j], name[j + 1]);
    //             strcpy(name[j + 1], temp);
    //         }
    //     }
    // }

    // for (int p = 0; p < n; p++)
    // {
    //     printf("%s ", name[p]);
    // }

    int array1[6] = {0, 1, 2, 3, 4, 5};
    int array2[3] = {6, 7, 8};

    int *pnt1 = array1;
    int *pnt2 = array2;

    int temp;

    for (int i = 0; i < 3; i++)
    {
        temp = *(pnt2 + i);
        *(pnt2 + i) = *(pnt1 + i);
        *(pnt1 + i) = temp;
    }

    printf("Mang 1 la:\n");

    for (int p = 0; p < 6; p++) {
        printf("%d ", *(pnt1 + p));
    }

    printf("\nMang 2 la:\n");

    for (int p = 0; p < 3; p++) {
        printf("%d ", *(pnt2 + p));
    }

    return 0;
}