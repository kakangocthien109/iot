#include<stdio.h>
int main() {
    int a, b, c;
    printf("Xin vui long nhap so thu nhat\n");
    scanf("%d", &a);
    printf("\nXin vui long nhap so thu hai\n");
    scanf("%d", &b);
    
    printf("\nSo thu nhat da nhap: %d\n", a);
    printf("\nSo thu hai da nhap: %d\n", a);
    c = a/b;

    printf("\nThuong cua 2 so %d va %d la %d", a, b, c);
    printf("\n Nhan phim bat ky de tiep tuc...");
    getchar();
}