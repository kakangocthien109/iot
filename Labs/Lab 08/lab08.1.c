#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int UCLN(int u, int v)
{
    int temp;
    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }
}
return u;
}

float giatrituyetdoi(float x)
{
    if (x < 0)
    {
        x = -x;
    }
    return x;
}

float canbachaive(float x) {
    const float epsilon = .00001;
    float guess = 1.0;

    if (x < 0) {
        printf("Khong the tinh can bac hai so am.\n");
        guess = -1.0;
    }
    else {
        while (giatrituyetdoi(guess * guess - x) >= epsilon) {
            guess = (x / guess + guess) / 2.0;
        }
    }
    return guess;
}

int main() {
    UCLN();
    giatrituyetdoi();
    canbachaive();

    return 0;
}