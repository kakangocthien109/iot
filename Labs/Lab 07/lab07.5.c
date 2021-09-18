#include <stdio.h>

int main()
{
    int a[101];
    int n;
    do
    {
        printf("Xin vui long nhap so luong phan tu: ");
        scanf("%d", &n);
        if (n < 0)
            printf("So luong phan tu khong hop le.\n");
    } while (n < 0);

    printf("Xin vui long nhap %d phan tu cho mang:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep giam dan la:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

        for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nMang sau khi sap xep tang dan la:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}