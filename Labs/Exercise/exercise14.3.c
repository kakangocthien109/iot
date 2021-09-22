 #include <stdio.h>
 #include <math.h>

 int main() {
     float a;
     printf("Xin vui long nhap so: ");
     scanf("%f", &a);
     printf("Luy thua cua so %.2f la %g\n", a, pow(a, 2));
     printf("Can bac 2 cua so %.2f la %.2f\n", a, sqrt(a));

     return 0;  


 }