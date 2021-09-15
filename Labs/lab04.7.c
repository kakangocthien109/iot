#include<stdio.h>
int main() {
    float a, b, c, d, e;
    printf("Xin vui long nhap so a\n");
    scanf("%f", &a);
    printf("\nXin vui long nhap so b\n");
    scanf("%f", &b);
    printf("Xin vui long nhap so c\n");
    scanf("%f", &c);
    printf("\nXin vui long nhap so d\n");
    scanf("%f", &d);
    
    printf("\n %d\n", a);
    printf("\n Cac so ban da nhap la:\n");
    printf("a = %.2f", a);
    printf("b = %.2f", b);
    printf("c = %.2f", c);
    printf("d = %.2f", d);
    
    e = (a+b+c+d)/4;

    printf("\nTrung binh cong cua a, b, c, d %.2f", e);
    printf("\n Nhan phim bat ky de tiep tuc...");
    getchar();
}