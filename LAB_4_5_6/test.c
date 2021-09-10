#include<stdio.h>
int main() {
    int a;
    float b;
    double c;
    c = 6.92;
    a = (int) c;
    c = (double) a;
    a = 112;
    char d = (char) a;
    int e = (a == 104) ? 10 : 22;
    printf ("%d \n", a);
    printf ("%lf \n", c);
    printf ("%c \n", d);
    printf ("%d \n", e);
    switch(a) {
        case 110:       printf("110 \n");
        break;
        case 145:         printf("145 \n");
        break;
        case 28:         printf("28 \n");
        break;
        case 52:         printf("52 \n");
        break;
        case 48:         printf("48 \n");
        break;
        case 64:         printf("64 \n");
        break;
        default:           printf("Day la gia tri mac dinh \n");
        // break;
    }

    for(a = 5 ; a < 10 ; a++ ) {
        if (a == 7)
        continue;
        printf("%d ", a);
    }

    printf(" \n");


 while( a < 30 ) {
        if (a == 27) {
            a++;
            continue;
        }
        printf("%d ", a++);  // In a trước rồi tăng a lên 1      
    }
    printf(" \n");

    return 0;
}