#include <stdio.h>
int main()
{

float arr[2][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
};

for (int i = 0; i < 2; i++) {
    for (int f = 0; f < 5; f++) {
        printf ("Xin vui long nhap phan tu [%d][%d]\n", i, f);
        scanf("%g", &arr[i][f]);
        // printf("%g ", arr[i][f]);
    }
    printf("\n");
}


for (int i = 0; i < 2; i++) {
    for (int f = 0; f < 5; f++) {
        printf("%3g ", arr[i][f]);
    }
    printf("\n");
}

}