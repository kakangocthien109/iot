/* 
-------------------------------------------------------------------------------
- ĐK 1 tam giác: tổng 2 cạnh bất kỳ > cạnh còn lại
- MN + GN > MG
- MN + MG > GN
- GN + MG > MN
(Cần thỏa mãn 3 đk)
-------------------------------------------------------------------------------
- ĐK 1 TG vuông:
- MG^2 = MG ^ 2 + NG ^ 2
- MG^2 = MN^2 + NG^2
- NG^2 = MG^2 + MN^2 
*/

#include <stdio.h>
#include <math.h>

int kiemtra_tamgiac(float ax, float ay, float bx, float by, float cx, float cy)
{
    float ab, bc, ca;

    ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    ca = sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));

    if (ab + bc > ca && ab + ca > bc && bc + ca > ab)
    {
        return 1;
    }
    return 0;
}

int main()
{
    float ax, ay, bx, by, cx, cy;

    do
    {
        printf("Xin vui long nhap toa do diem A: \n");
        scanf("%f", &ax);
        scanf("%f", &ay);

        printf("Xin vui long nhap toa do diem B: \n");
        scanf("%f", &bx);
        scanf("%f", &by);

        printf("Xin vui long nhap toa do diem C: \n");
        scanf("%f", &cx);
        scanf("%f", &cy);

        printf("\n------------------------------------\n");
        printf("Toa do diem A da nhap: A(%.2f, %.2f) \n", ax, ay);
        printf("Toa do diem B da nhap: B(%.2f, %.2f) \n", bx, by);
        printf("Toa do diem C da nhap: C(%.2f, %.2f) \n\n", cx, cy);

        if (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)))
        {
            printf("Cac toa do da nhap khong tao thanh 1 tam giac \n");
            printf("Xin vui long nhap lai \n\n");
        }
    } while (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)));

    printf("Cac toa do da nhap tao thanh 1 tam giac \n");

    return 0;
}