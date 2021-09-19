#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fw = fopen("test.txt", "w");
    
    char nhap [1000];

    printf("Xin vui long nhap noi dung:\n");
    scanf("%[^\n]s", nhap);
    fprintf(fw, "%s", nhap);

    fclose(fw);
    fw = NULL;
}