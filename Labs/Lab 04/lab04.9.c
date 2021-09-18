/* Bài 4.9:
Yêu cầu: Nhập dữ liệu từ bàn phím về nhân viên bao gồm: ID nhân viên, tổng số giờ làm việc
1 tháng, số tiền nhận được mỗi giờ. Đưa ra màn hình ID nhân viên, tiền lương nhận được của
tháng.

Hướng dẫn:
- Bước 1: Khai báo 4 biến kiểu dữ liệu unsigned int sau: ID nhân viên, số giờ làm
việc, tiền lương mỗi giờ và tiền lương của tháng.
- Bước 2: Nhập vào từ bàn phím ID nhân viên, tổng số giờ làm việc và tiền lương mỗi
giờ.
- Bước 3: Cách tính tiền lương:
tiền lương = số giờ làm việc x tiền lương mỗi giờ */

#include <stdio.h>

int main() {
    unsigned int id, hours, hourssalary, monthssalary;

    printf("Xin vui long nhap ID nhan vien: ");
    scanf("%d", &id);
    printf("Xin vui long tong nhap so gio lam viec: ");
    scanf("%d", &hours);
    printf("Xin vui long nhap tien luong moi gio: ");
    scanf("%d", &hourssalary);

    monthssalary = (hourssalary * hours);

    printf("Tien luong moi thang cua nhan vien co ID: %d la: %d\n", id, monthssalary);
    getchar();

    return 0;

}