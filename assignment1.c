#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define PI 3.14159265
#define sep "\n------------------------------------\n\n"
#define toado "Xin vui long nhap toa do diem"

float toa_do[6];
float canh_goc[6]; 
float dc[3]; // Duong cao tam giac
float tt[3]; // Trung tuyen tam giac
float p; // Nua chu vi TG

void duongcao_tamgiac()
{
  p = (canh_goc[2] + canh_goc[1] + canh_goc[0]) / 2.0;
  dc[0] = ((2 * (sqrt(p * (p - canh_goc[2]) * (p - canh_goc[1]) * (p - canh_goc[0])))) / canh_goc[2]);
  dc[1] = ((2 * (sqrt(p * (p - canh_goc[2]) * (p - canh_goc[1]) * (p - canh_goc[0])))) / canh_goc[1]);
  dc[2] = ((2 * (sqrt(p * (p - canh_goc[2]) * (p - canh_goc[1]) * (p - canh_goc[0])))) / canh_goc[0]);
  printf(sep "3. So do nang cao tam giac ABC:\n");
  printf("Do dai duong cao tu dinh A la: %.2f \n", dc[0]);
  printf("Do dai duong cao tu dinh B la: %.2f \n", dc[1]);
  printf("Do dai duong cao tu dinh C la: %.2f \n", dc[2]);
}
void dientich_tamgiac()
{
  p = (canh_goc[2] + canh_goc[1] + canh_goc[0]) / 2.0;
  float s = sqrt(p * (p - canh_goc[2]) * (p - canh_goc[1]) * (p - canh_goc[0]));
  printf(sep);
  printf("2. Dien tich tam giac la: %.2f \n", s);
}
void tinhcanh()
{
  canh_goc[0] = sqrt((toa_do[0] - toa_do[2]) * (toa_do[0] - toa_do[2]) + (toa_do[1] - toa_do[3]) * (toa_do[1] - toa_do[3]));
  canh_goc[1] = sqrt((toa_do[0] - toa_do[4]) * (toa_do[0] - toa_do[4]) + (toa_do[1] - toa_do[5]) * (toa_do[1] - toa_do[5]));
  canh_goc[2] = sqrt((toa_do[2] - toa_do[4]) * (toa_do[2] - toa_do[4]) + (toa_do[3] - toa_do[5]) * (toa_do[3] - toa_do[5]));
}

void xet_tamgiac()
{
  char dactinh[4]; // Vuong, tu, can, deu
  if ((canh_goc[3] - 90.0f < 0.000001f) && (canh_goc[3] - 90.0f >= 0.0f) || (canh_goc[3] - 90.0f > -0.000001f) && (canh_goc[3] - 90.0f <= 0.0f))
    dactinh[0] = 'A';
  else if ((canh_goc[4] - 90.0f < 0.000001f) && (canh_goc[4] - 90.0f >= 0.0f) || (canh_goc[4] - 90.0f > -0.000001f) && (canh_goc[4] - 90.0f <= 0.0f))
    dactinh[0] = 'B';
  else if ((canh_goc[5] - 90.0f < 0.000001f) && (canh_goc[5] - 90.0f >= 0.0f) || (canh_goc[5] - 90.0f > -0.000001f) && (canh_goc[5] - 90.0f <= 0.0f))
    dactinh[0] = 'C';
  else
    dactinh[0] = '0';

  if (canh_goc[3] > 90.0f)
    dactinh[1] = 'A';
  else if (canh_goc[4] > 90.0f)
    dactinh[1] = 'B';
  else if (canh_goc[5] > 90.0f)
    dactinh[1] = 'C';
  else
    dactinh[1] = '0';

  if (canh_goc[2] == canh_goc[1])
    dactinh[2] = 'C';
  else if (canh_goc[2] == canh_goc[0])
    dactinh[2] = 'B';
  else if (canh_goc[1] == canh_goc[0])
    dactinh[2] = 'A';
  else
    dactinh[2] = '0';

  if (canh_goc[2] == canh_goc[1] && canh_goc[1] == canh_goc[0] && canh_goc[2] == canh_goc[0])
    dactinh[3] = '1';
  else
    dactinh[3] = '0';

  if (dactinh[0] != '0' && dactinh[2] != '0')
    printf("Tam giac vuong can tai %c\n", dactinh[0]);
  else if (dactinh[1] != '0' && dactinh[2] != '0')
    printf("Tam giac tu va can tai %c", dactinh[1]);
  else if (dactinh[0] != '0')
    printf("Tam giac vuong tai %c\n", dactinh[0]);
  else if (dactinh[1] != '0')
    printf("Tam giac tu tai %c\n", dactinh[1]);
  else if (dactinh[2] != '0')
    printf("Tam giac can tai %c\n", dactinh[2]);
  else if (dactinh[3] != '0')
    printf("Tam giac deu\n");
  else
    printf("Tam giac nhon\n");
}
void ingoc()
{
  float cosA = (canh_goc[1] * canh_goc[1] + canh_goc[0] * canh_goc[0] - canh_goc[2] * canh_goc[2]) / (2 * canh_goc[0] * canh_goc[1]);
  float cosB = (canh_goc[2] * canh_goc[2] + canh_goc[0] * canh_goc[0] - canh_goc[1] * canh_goc[1]) / (2 * canh_goc[0] * canh_goc[2]);
  float cosC = (canh_goc[2] * canh_goc[2] + canh_goc[1] * canh_goc[1] - canh_goc[0] * canh_goc[0]) / (2 * canh_goc[2] * canh_goc[1]);
  canh_goc[3] = acos(cosA) * 180 / PI;
  canh_goc[4] = acos(cosB) * 180 / PI;
  canh_goc[5] = acos(cosC) * 180 / PI;
  printf("So do goc A la: %.2f \n", canh_goc[3]);
  printf("So do goc B la: %.2f \n", canh_goc[4]);
  printf("So do goc C la: %.2f \n", canh_goc[5]);
}

void trungtuyen_tamgiac()
{

  tt[0] = sqrt((canh_goc[1] * canh_goc[1] + canh_goc[0] * canh_goc[0]) / 2 - (canh_goc[2] * canh_goc[2]) / 4);
  tt[1] = sqrt((canh_goc[2] * canh_goc[2] + canh_goc[0] * canh_goc[0]) / 2 - (canh_goc[1] * canh_goc[1]) / 4);
  tt[2] = sqrt((canh_goc[1] * canh_goc[1] + canh_goc[2] * canh_goc[2]) / 2 - (canh_goc[0] * canh_goc[0]) / 4);
  printf("Do dai trung tuyen tu dinh A la: %.2f \n", tt[0]);
  printf("Do dai trung tuyen tu dinh B la: %.2f\n", tt[1]);
  printf("Do dai trung tuyen tu dinh C la: %.2f\n", tt[2]);
}

void tam_tamgiac()
{
  float g = (toa_do[0] + toa_do[2] + toa_do[4]) / 3;
  float h = (toa_do[1] + toa_do[3] + toa_do[5]) / 3;

  printf(sep "4. Toa do diem dac biet cua tam giac ABC:\n");
  printf("Toa do trong tam: [%.2f, %.2f]", g, h);
}

void incanh()
{
  printf(sep);
  printf("1. Cac so do co ban cua tam giac:\n");
  printf("Chieu dai cua canh AB la: %.2f \n", canh_goc[0]);
  printf("Chieu dai cua canh BC la: %.2f \n", canh_goc[2]);
  printf("Chieu dai cua canh AC la: %.2f \n", canh_goc[1]);
}

void inketqua()
{
  incanh();
  ingoc();
  xet_tamgiac();
  dientich_tamgiac();
  duongcao_tamgiac();
  trungtuyen_tamgiac();
  tam_tamgiac();
}

int check_tamgiac()
{
  tinhcanh();
  if (canh_goc[2] + canh_goc[1] > canh_goc[0] && canh_goc[2] + canh_goc[0] > canh_goc[1] && canh_goc[1] + canh_goc[0] > canh_goc[2])
  {
    return 1;
  }
  return 0;
}
int main()
{
  do
  {
    printf(sep);
    printf(toado " cua diem A - Ax: ");
    scanf("%f", &toa_do[0]);
    printf(toado " cua diem A - Ay: ");
    scanf("%f", &toa_do[1]);
    printf(toado " cua diem B - Bx: ");
    scanf("%f", &toa_do[2]);
    printf(toado " cua diem B - By: ");
    scanf("%f", &toa_do[3]);
    printf(toado " cua diem C - Cx: ");
    scanf("%f", &toa_do[4]);
    printf(toado " cua diem C - Cy: ");
    scanf("%f", &toa_do[5]);
    printf(sep);
    printf("Toa do diem A da nhap: A(%.2f; %.2f) \n", toa_do[0], toa_do[1]);
    printf("Toa do diem B da nhap: B(%.2f; %.2f) \n", toa_do[2], toa_do[3]);
    printf("Toa do diem C da nhap: C(%.2f; %.2f) \n", toa_do[4], toa_do[5]);
    if (!(check_tamgiac(toa_do[0], toa_do[1], toa_do[2], toa_do[3], toa_do[4], toa_do[5])))
    {
      printf(sep "Toa do 3 diem da nhap khong hop thanh 1 tam giac \nXin vui long nhap lai toa do \n");
    }
  } while (!(check_tamgiac(toa_do[0], toa_do[1], toa_do[2], toa_do[3], toa_do[4], toa_do[5])));
  printf(sep "Toa do 3 diem da nhap tao thanh 1 tam giac \n");
  inketqua();
}
