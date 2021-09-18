#include <stdio.h>
int main() {
    char str1[] = "nguyennt.dev";
    char str2[] = "quocthinhvo.dev";

    char *pnt1 = str1;
    char *pnt2 = str2;

    int i, j;

    while (*(pnt1+i) != '\0') {
        i++;
    }
    i--;

    for (j = i; j >= 0; j--) {
        printf("%c", pnt1[j]);
    }

    printf("\n");

    while (*(pnt2+i) != '\0') {
        i++;
    }
    i--;

    for (j = i; j >= 0; j--) {
        printf("%c", pnt2[j]);
    }

}