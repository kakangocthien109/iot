#include<stdio.h>
int main() {
     int a;
     int b;
     printf("Nhap so nguyen a: ");
     scanf("%d", &a);
     printf("Nhap so nguyen b: ");
     scanf("%d", &b);    
     printf("Tong cua %ld va %ld la: %ld ", a, b, a + b);
     return 0;
}