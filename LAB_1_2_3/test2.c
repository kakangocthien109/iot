#include <stdio.h>
int main() {
    char a;
    int b;
    float c;
    double d;
    long int e;
    long int f;
    int g = 1;
    e = 8613274197;
    d = -192.7310;
    c = 3.141716;
    b = -17;
    a ='h';
    enum month {Jan, Feb, Mar, Apr = 10, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum month thisMonth;
    thisMonth = Sep;
    printf("%c \n", a + 1); 
    printf("%d \n", b);
    printf("%f \n", c); 
    printf("%g \n", c);
    printf("%f \n", d); 
    printf("%g \n", d);
    printf("%ld \n", e);
    printf("%d \n", g);
    printf("%.3f \n", c);
    printf("%d \n", thisMonth);
    return 0;
}