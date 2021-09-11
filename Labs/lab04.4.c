#include <stdio.h>
int main()
{
    /*
    - This is lab 4.2, created by nguyennt.dev
    - Date of creation: 10/09/2021
    - Date of modified: 10/09/2021
    - Goal of this project: Input and output data using scanf and printf
    */
    int a; // Minutes
    int b;  // Dates
    int c;  // Years
    int d;

        printf("------------------------------------------------------------------------------- \n\n");
        printf("Xin vui long nhap so phut: \n\n");
        scanf("%d", &a);
        printf("------------------------------------------------------------------------------- \n \n");

        b = a / 60 / 24;
        c = a / 365;
        d =  a - (b * 1440) - (c * 365);

        printf("So phut ban da nhap: %d \n", a);
        printf(" \n");
        printf("------------------------------------------------------------------------------- \n \n");
        printf("So ngay quy doi duoc tu so phut la %d \n",b);
        printf("So nam quy doi duoc tu so phut la %d \n", c);
        printf("So phut bi du la %d phut \n\n", d);
        printf("------------------------------------------------------------------------------- \n");

        printf("Vay %d phut doi duoc thanh %d nam, %d ngay va %d phut. \n\n ", a, c, b,d);

    return 0;
}