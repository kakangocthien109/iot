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

float A, B, C;
float c, a, b, h;
float dca, dcb, dcc;

float tindccanh(float ax, float ay, float bx, float by)
{
    float ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    return ab;
}

void ingoc()
{
    float cosA = (b * b + c * c - a * a) / (2 * c * b);
    float cosB = (a * a + c * c - b * b) / (2 * c * a);
    float cosC = (a * a + b * b - c * c) / (2 * a * b);

    A = acos(cosA) * 180 / PI;
    B = acos(cosB) * 180 / PI;
    C = acos(cosC) * 180 / PI;

    printf("\n------------------------------------\n\n");
    printf("So do goc A la %.2f \n", A);
    printf("So do goc B la %.2f \n", B);
    printf("So do goc C la %.2f \n", C);
}

void xet_tamgiac()
{
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("\n------------------------------------\n\n");
        if (A - 90 < 0.000001 && 90 - A < -0.000001)
            printf("Day la tam giac vuong tai goc A \n");
        if (B - 90 < 0.000001 && 90 - B < -0.000001)
            printf("Day la tam giac vuong tai goc B \n");
        if (C - 90 < 0.000001 && 90 - C < -0.000001)
            printf("Day la tam giac vuong tai goc C \n");

        if (A > 90)
            printf("Day la tam giac tu tai goc A \n");
        if (B > 90)
            printf("Day la tam giac tu tai goc B \n");
        if (C > 90)
            printf("Day la tam giac tu tai goc C \n");

        if (a == b && b == c && a == c)
            printf("Day la tam giac deu \n");

        if (a == b || a == c || b == c)
            printf("Day la tam giac can \n");
        if (a < 90 && b < 90 && c < 90 && a != b && b != c && c != a)
            printf("Day la tam giac nhon \n");
    }
    else
    {
        printf("Day khong pdcai la mot tam giac \n");
    }
}

void dientich_tamgiac()
{
    float p = (a + b + c) / 2.0;
    float s = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("\n------------------------------------\n");
    printf("\nDien tich tam giac la: %.2f \n", s);
}

void duongcao_tamgiac()
{
    float p = (a + b + c) / 2.0;
    dca = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / a);
    dcb = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / b);
    dcc = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / c);

    printf("\n------------------------------------\n\n");
    printf("Duong cao dinh A la %.2f \n", dca);
    printf("Duong cao dinh B la %.2f \n", dcb);
    printf("Duong cao dinh C la %.2f \n", dcc);
    printf("\n------------------------------------\n\n");
}

void incanhgoc(float ax, float ay, float bx, float by, float cx, float cy)
{
    c = tindccanh(ax, ay, bx, by);
    a = tindccanh(bx, by, cx, cy);
    b = tindccanh(ax, ay, cx, cy);

    printf("\n------------------------------------\n\n");
    printf("Chieu dai cua canh AB la %.2f \n", c);
    printf("Chieu dai cua canh BC la %.2f \n", a);
    printf("Chieu dai cua canh AC la %.2f \n", b);

    ingoc(b, c, a);
    xet_tamgiac(a, b, c);
    dientich_tamgiac();
    duongcao_tamgiac();
}

int kiemtra_tamgiac(float ax, float ay, float bx, float by, float cx, float cy)
{
    float ab, bc, ca;

    ab = tindccanh(ax, ay, bx, by);
    bc = tindccanh(bx, by, cx, cy);
    ca = tindccanh(ax, ay, cx, cy);

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
        printf("Xin vui long nhap toa do diem Ax: \n");
        scanf("%f", &ax);
        printf("Xin vui long nhap toa do diem Ay: \n");
        scanf("%f", &ay);

        printf("Xin vui long nhap toa do diem Bx: \n");
        scanf("%f", &bx);
        printf("Xin vui long nhap toa do diem By: \n");
        scanf("%f", &by);

        printf("Xin vui long nhap toa do diem Cx: \n");
        scanf("%f", &cx);
        printf("Xin vui long nhap toa do diem Cy: \n");
        scanf("%f", &cy);

        printf("\n------------------------------------\n\n");
        printf("Toa do diem A da nhap: A(%.2f, %.2f) \n", ax, ay);
        printf("Toa do diem B da nhap: B(%.2f, %.2f) \n", bx, by);
        printf("Toa do diem C da nhap: C(%.2f, %.2f) \n", cx, cy);

        if (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)))
        {
            printf("\n------------------------------------\n\n");
            printf("Cac toa do da nhap khong tao thanh 1 tam giac \n\n");
            printf("Xin vui long nhap lai \n");
            printf("\n------------------------------------\n\n");
        }

    } while (!(kiemtra_tamgiac(ax, ay, bx, by, cx, cy)));

    printf("\n------------------------------------\n\n");
    printf("Cac toa do da nhap tao thanh 1 tam giac \n");

    incanhgoc(ax, ay, bx, by, cx, cy);

    return 0;
}
