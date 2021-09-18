#include <stdio.h>

struct ngaysinh
{
    int ngay, thang;
};

struct nhanvien
{
    char ten[30];
    char id[30];
    float luong;
    struct ngaysinh nns;
};
int main()
{
    struct nhanvien n;
    printf("Xin vui long nhap ten nhan vien: ");
    scanf("%s", &n.ten);
    printf("Xin vui long nhap ID nhan vien: ");
    scanf("%s", &n.id);
    printf("Xin vui long nhap luong nhan vien: ");
    scanf("%f", &n.luong);
    printf("Xin vui long nhap ngay sinh: ");
    scanf("%d", &n.nns.ngay);
    printf("Xin vui long nhap thang sinh: ");
    scanf("%d", &n.nns.thang);

    printf("\nThong tin chi tiet:\n");
    printf("Ten nhan vien: %10s\n", n.ten);
    printf("ID nhan vien: %12s\n", n.id);
    printf("Luong nhan vien: %9.2f\n", n.luong);
    printf("Ngay sinh la: %8d/%d", n.nns.ngay, n.nns.thang);


    return 0;
}