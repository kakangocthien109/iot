#include <stdio.h>
#include <string.h>

#define PAYRATE 12.00
#define OVERTIME 40

int main()
{
    int hours = 0;
    double grossPay = 0.0, taxes = 0.0, netPay = 0.0;
    int over;

    printf("Xin vui long nhap so gio lam viec:\n");
    scanf("%d", &hours);

    grossPay = 12.00f * hours;

    over = hours - 40;

    if (over > 0)
        grossPay = grossPay + (over * (12.00 * 1.5));

    if (grossPay <= 300.0f)
        taxes = grossPay * (0.15f) / 100;

    if (grossPay > 300.0f && grossPay <= 450.0f)
        taxes = grossPay * (0.2f) / 100;

    if (grossPay > 450.0f)
        taxes = grossPay * (0.25f) / 100;

    netPay = grossPay - taxes;

    printf("Luong Net: %.2f \n", netPay);
    printf("Thue: %.2f \n", taxes);
    printf("Luong Gross: %.2f \n", grossPay);

    return 0;
}