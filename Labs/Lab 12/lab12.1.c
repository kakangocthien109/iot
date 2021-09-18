#include <stdio.h>

struct nhanvien
{
    char ten[30];
    char id[30];
    float luong;
};
int main()
{
    struct nhanvien n;
    printf("Xin vui long nhap ten nhan vien: ");
    scanf("%s", &n.ten);
    printf("Xin vui long nhap id nhan vien: ");
    scanf("%s", &n.id);
    printf("Xin vui long nhap luong nhan vien: ");
    scanf("%f", &n.luong);

    printf("\nThong tin chi tiet:\n");
    printf("Ten nhan vien: %10s\n", n.ten);
    printf("ID nhan vien: %12s\n", n.id);
    printf("Luong nhan vien: %9.2f\n", n.luong);

    return 0;
}