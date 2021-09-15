#include <stdio.h>
int main()
{
    int a, b, c, d;
    printf("Xin vui long nhap so a\n");
    scanf("%d", &a);
    printf("\nXin vui long nhap so b\n");
    scanf("%d", &b);
    printf("Xin vui long nhap so c\n");
    scanf("%d", &c);
    printf("\nXin vui long nhap so d\n");
    scanf("%d", &d);

    printf("\n %d\n", a);
    printf("\n Cac so ban da nhap la:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    a = a * a;
    b = b * b;
    c = c * c;
    d = d * d;

    printf("\nBinh phuong cua so a la", a);
    printf("\nBinh phuong cua so b la", b);
    printf("\nBinh phuong cua so c la", c);
    printf("\nBinh phuong cua so d la", d);

    printf("\nTrung binh cong cua a, b, c, d %.2f", e);
    printf("\n Nhan phim bat ky de tiep tuc...");
    getchar();
}