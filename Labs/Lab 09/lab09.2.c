#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n;
    printf("Xin vui long nhap so luong chuoi ky tu: ");
    scanf("%d", &n);
    char name[30][30];
    char temp[30] = "";

    for (i = 0; i < n; i++)
    {
        printf("Xin vui long nhap chuoi thu %d: ", i);
        scanf("%s", name[i]);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (strcmp(name[j], name[j + 1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }

    for (int p = 0; p < n; p++)
    {
        printf("%s ", name[p]);
    }

    return 0;
}