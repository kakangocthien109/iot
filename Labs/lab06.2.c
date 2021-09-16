#include <stdio.h>

int main()
{
    int a = 65, b = 0;
    do
    {
        printf("Xin vui long nhap so ban doan: "); // Duong Tran 2
        scanf("%f", &b);
        if (b - a == 0  )
            printf("Xin chuc mung! Ban da doan dung! \n");

        if (!(b == a))
        {
            printf("So ban da nhap khong chinh xac! \nXin vui long thu lai \n");
        }
    } while (!(b == a));

    return 0;
}