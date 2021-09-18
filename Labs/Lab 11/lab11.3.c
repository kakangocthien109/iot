#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n;
    printf("Xin vui long nhap so luong phan tu: ");
    scanf("%d", &n);
    int array[n];
    int *pointer = array;

    for (i = 0; i < n; i++)
    {
        printf("Xin vui long nhap phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    int max = *pointer;
    for (i = 0; i < n; i++) {
        if (max < *(pointer + i)) {
            max = *(pointer + i);
        }
    }

    printf("=> Phan tu lon nhat la %d", max);

    return 0;
}