#include <stdio.h>
#include <stdlib.h>
#define max 30

int main()
{
    char oldname[max], newname[max], buffer[max];

    printf("Hay nhap ten file can doi \n");
    scanf("%s", oldname);

    printf("Hay nhap ten file moi \n");
    scanf("%s", newname);

    int re = rename(oldname, newname);

    if (re == 0)
    {
        printf("Doi ten file thanh cong!\n");
    }
    else
    {
        printf("Doi ten file that bai!\n");
    }

    getchar();

    printf("Hay nhap ten file can xoa\n");
    scanf("%s", buffer);
    int rem = remove(buffer);
    if (rem == 0)
    {
        printf("Xoa file thanh cong!\n");
    }
    else
    {
        printf("Xoa file that bai!\n");
    }
    return 0;
}