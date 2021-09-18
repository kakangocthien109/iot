#include <stdio.h>
#include <string.h>
#define sep "\n--------------------------------\n"

struct hocsinh
{
    char hoten[25];
    int tuoi;
    char diachi[128];
    float gpa;
};

int main()
{
    struct hocsinh hs[100];
    int choice, num;
    char ten[30];
    printf("\e[1;1H\e[2J");
    printf("Vui long nhap lua chon cua ban:\n");
    printf("1. Nhap thong tin hoc sinh\n");
    printf("2. Tim kiem hoc sinh\n");
    printf("3. Thoat\n");
    scanf("%d", &choice);
    printf(sep);

    switch (choice)
    {
    case 1:
        printf("Vui long nhap so luong hoc sinh muon them: ");
        int them = 0;
        scanf("%d", &them);

        for (int i = 0; i < them; i++)
        {
            printf(sep);
            printf("Xin vui long nhap thong tin sinh vien thu %d\n", i + num);
            printf("Xin vui long nhap cac thong tin sau:\n");
            printf(sep);
            printf("- Ho va ten: ");
            fflush(stdin);
            gets(hs[i].hoten);
            printf("- Tuoi: ");
            scanf("%d", &hs[i].tuoi);
            printf("- Dia chi: ");
            fflush(stdin);
            gets(hs[i].diachi);
            printf("- GPA: ");
            scanf("%f", &hs[i].gpa);
            printf(sep);
        }

        num = num + them;
        break;

    case 2:
        printf(sep);
        printf("Vui long nhap ten sinh vien muon tim kiem:\n");
        scanf("%s", ten);

        for (int i = 0; i < num; i++)
        {
            if (strcmp(ten, hs[i].hoten) == 0)
            {
                printf("Da tim thay hoc sinh.\n");
                printf(sep);
                printf("Thong tin cua hoc sinh %s la: \n", ten);
                printf("- Ho va ten: %s", hs[i].hoten);
                printf("- Tuoi: %d", &hs[i].tuoi);
                printf("- Dia chi: %s", &hs[i].diachi);
                printf("- GPA: %f", &hs[i].gpa);
                printf(sep);
                break;
            }
            if (i == num)
            {
                printf("Khong tim thay hoc sinh.\n");
            }
        }
        break;

    case 3:
        break;
    }
    return 0;
}