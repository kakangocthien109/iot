#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define PI 3.14159265
#define sep "\n------------------------------------\n\n"
#define toado "Xin vui long nhap toa do diem"
float ax, ay, bx, by, cx, cy, a, b, c, A, B, C, p, dca, dcb, dcc;
float tt[3];
void duongcao_tamgiac()
{
  p = (a + b + c) / 2.0;
  dca = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / a);
  dcb = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / b);
  dcc = ((2 * (sqrt(p * (p - a) * (p - b) * (p - c)))) / c);
  printf(sep);
  printf("Duong cao dinh A la %.2f \n", dca);
  printf("Duong cao dinh B la %.2f \n", dcb);
  printf("Duong cao dinh C la %.2f \n", dcc);
  printf(sep);
}
void dientich_tamgiac()
{
  p = (a + b + c) / 2.0;
  float s = sqrt(p * (p - a) * (p - b) * (p - c));
  printf(sep);
  printf("Dien tich tam giac la: %.2f \n", s);
}
float tinhcanh(float ax, float ay, float bx, float by)
{
  float a = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  return a;
}

void loai_tamgiac()
{
  printf(sep);
  if (A > 90)
  {
    printf("Day la tam giac tu tai goc A \n");
  }
  else if (B > 90)
  {
    printf("Day la tam giac tu tai goc B \n");
  }
  else if (C > 90)
  {
    printf("Day la tam giac tu tai goc C \n");
  }
  if (a == b && b == c && a == c)
    printf("Day la tam giac deu \n");
  if (a == b || a == c || b == c)
    printf("Day la tam giac can \n");
  if (A - 90 < 0.000001 && 90 - A < -0.000001)
    printf("Day la tam giac vuong tai goc A \n");
  else if (B - 90 < 0.000001 && 90 - B < -0.000001)
    printf("Day la tam giac vuong tai goc B \n");
  else if (C - 90 < 0.000001 && 90 - C < -0.000001)
    printf("Day la tam giac vuong tai goc C \n");
  if (a < 90 && b < 90 && c < 90 && a != b && b != c && c != a)
    printf("Day la tam giac nhon \n");
}
void ingoc()
{
  float cosA = (b * b + c * c - a * a) / (2 * c * b);
  float cosB = (a * a + c * c - b * b) / (2 * c * a);
  float cosC = (a * a + b * b - c * c) / (2 * a * b);
  A = acos(cosA) * 180 / PI;
  B = acos(cosB) * 180 / PI;
  C = acos(cosC) * 180 / PI;
  printf(sep "So do goc A la %.2f \n", A);
  printf("So do goc B la %.2f \n", B);
  printf("So do goc C la %.2f \n", C);
}

void

trungtuyen_tamgiac()
{

  // ma = b(2b2 + 2c2 b