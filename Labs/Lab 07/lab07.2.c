#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);
    int array[len];

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = len -1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }



    return 0;
}