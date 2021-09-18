#include <stdio.h>

int main()
{
    int a = 65, b = 0;
    do
    {
        printf("Xin vui long nhap so ban doan: ");
        scanf("%d", &b);
            

        if (!(b == a))
        {
            printf("So ban da nhap khong chinh xac! \nXin vui long thu lai \n");
        }
    } while (!(b == a));
    printf("Xin chuc mung! Ban da doan dung! \n");

    return 0;
}