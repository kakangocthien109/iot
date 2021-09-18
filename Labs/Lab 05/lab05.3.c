#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    printf("Xin vui long ket qua cam bien nhiet do\n");
    scanf("%d", &a);

    if ((a != (int)a))
    {
        printf("Ket qua cam bien nhiet do da nhap khong hop le, xin vui long thu lai. \n");
    }
    else
    {

        if (a <= 0)
        {
            printf("Thoi tiet lanh cong\n");
        }
        else if (a > 0 && a <= 10)
        {
            printf("Thoi tiet rat lanh\n");
        }
        else if (a > 10 && a <= 20)
        {
            printf("Thoi tiet lanh\n");
        }
        else if (a > 20 && a <= 30 )
        {
            printf("Thoi tiet tuyet voi\n");
        }
        else if (a > 30 && a <= 40 )
        {
            printf("Thoi tiet nong\n");
        }
        else if (a >=40)
        {
            printf("Thoi tiet rat nong\n");
        }
    }
    getchar();
    return 0;
}