#include <stdio.h>
int main()
{
    /*
    - This is lab 4.2, created by nguyennt.dev
    - Date of creation: 10/09/2021
    - Date of modified: 10/09/2021
    - Goal of this project: Input and output data using scanf and printf
    */
    int a; 
    int b;  
    int c;  
    int d;
        printf("------------------------------------------------------------------------------- \n\n");
        printf("Xin vui long nhap so ngay: \n\n");
        scanf("%d", &c);
        printf("------------------------------------------------------------------------------- \n \n");

        a = c / 365;
        b = (c - a * 365) / 7;
        d = c - (a * 365) - (b * 7);

        printf("So ngay ban da nhap: %d \n", c);
        printf(" \n");
        printf("------------------------------------------------------------------------------- \n \n");
        printf("So nam quy doi duoc tu so ngay la %d \n", a);
        printf("So tuan quy doi duoc tu so ngay la %d \n", b);
        printf("So ngay du la %d \n \n", d);
        printf("------------------------------------------------------------------------------- \n");

        printf("Vay %d ngay doi duoc thanh %d nam, %d tuan, %d ngay. \n\n ", c, a, b, d);

    return 0;
}