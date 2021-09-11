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

#define PI 3.14159265



float tinhcanh(float ax, float ay, float bx, float by)
{
    float ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    return ab;
}

void ingoc(float a, float b, float c)
{
    float cosA = (b * b + c * c - a * a) / (2 * c * b);
    float cosB = (a * a + c * c - b * b) / (2 * c * a);
    float cosC = (a * a + b * b - c * c) / (2 * a * b);

    float A = acos(cosA) * 180 / PI;
    float B = acos(cosB) * 180 / PI;
    float C = acos(cosC) * 180 / PI;

    printf("\n------------------------------------\n");
    printf("So do goc A la %.2f \n", A);
    printf("So do goc B la %.2f \n", B);
    printf("So do goc C la %.2f \n", C);
}

void incanhgoc(float ax, float ay, float bx, float by, float cx, float cy)
{
    float ab = tinhcanh(ax, ay, bx, by);
    float bc = tinhcanh(bx, by, cx, cy);
    float ca = tinhcanh(ax, ay, cx, cy);

    printf("\n------------------------------------\n");
    printf("Chieu dai cua canh AB la %.2f \n", ab);
    printf("Chieu dai cua canh BC la %.2f \n", bc);
    printf("Chieu dai cua canh AC la %.2f \n", ca);

    ingoc(bc, ca, ab);
}

int kiemtra_tamgiac(float ax, float ay, float bx, float by, float cx, float cy)
{
    float ab, bc, ca;

    ab = tinhcanh(ax, ay, bx, by);
    bc = tinhcanh(bx, by, cx, cy);
    ca = tinhcanh(ax, ay, cx, cy);

    if (ab + bc > ca && ab + ca > bc && bc + ca > ab)
    {
        return 1;
    }
    return 0;
}

int main()
{
    float ax, ay, bx, by, cx, cy, cosA, cosB, cosC;

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

        incanhgoc(ax, ay, bx, by, cx, cy);

        if (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)))
        {
            printf("Cac toa do da nhap khong tao thanh 1 tam giac \n");
            printf("Xin vui long nhap lai \n\n");
        }
    } while (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)));

    printf("Cac toa do da nhap tao thanh 1 tam giac \n");

    return 0;
}