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
int read_line(char str[]) {
    int c, i = 0;
    c = getchar();
    while (c != '\n' && c != EOF) { 
       str[i] = c;
       c = getchar();
       i++;
    }
    str[i] = '\0';
    return i;
}
int main()
{
    struct hocsinh hs[100];
    int choice, num;
    char ten[30];
    int hoat_dong = 1;
    while(hoat_dong){
        //printf("\e[1;1H\e[2J");
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
            fflush(stdin);
    
            for (int i = 0; i < them; i++)
            {
                printf(sep);
                printf("Nhap thong tin sinh vien thu %d\n", i + num +1);
                printf(sep);
                printf("Vui long nhap cac thong tin sau:");
                printf(sep);
                printf("- Ho va ten: ");
                char temp;
                scanf("%c",&temp); // temp statement to clear buffer
                scanf("%[^\n]s", hs[i].hoten);
                printf("- Tuoi: ");
                scanf("%d", &hs[i].tuoi);
                printf("- Dia chi: ");
                scanf("%c",&temp); // temp statement to clear buffer
                scanf("%[^\n]s", hs[i].diachi);
                printf("- GPA: ");
                scanf("%f", &hs[i].gpa);
                printf(sep);
            }
    
            num = num + them;
            break;
    
        case 2:
            printf(sep);
            char temp;
            scanf("%c",&temp); // temp statement to clear buffer
            printf("Vui long nhap ten hoc sinh muon tim kiem: ");
            scanf("%[^\n]s", ten);

            for (int i = 0; i < num; i++)
            {
                if (strcmp(ten, hs[i].hoten) == 0)
                {
                    printf("Da tim thay hoc sinh.\n");
                    printf(sep);
                    printf("Thong tin cua hoc sinh %s la: \n", ten);
                    printf("- Ho va ten: %s\n", hs[i].hoten);
                    printf("- Tuoi: %d\n", hs[i].tuoi);
                    printf("- Dia chi: %s\n", hs[i].diachi);
                    printf("- GPA: %f\n", hs[i].gpa);
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
            hoat_dong = 0;
            break;
        }
    }
    
}