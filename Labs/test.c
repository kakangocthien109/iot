// Có 1 mảng gồm 5 phần tử, giá trị là 10, 20, 5, 30, 11

#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL) {
        printf("Khong mo duoc file");
        return;
    }

    fclose(fp);
    fp = NULL;

    return 0;
}