#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    char str2[100];
    printf("Xin vui long nhap chuoi ky tu cho str1:\n");
    scanf("%[^\n]s", str1);
    
    printf("Xin vui long nhap chuoi ky tu cho str2:\n");
    char temp;
    scanf("%c", &temp);
    scanf("%[^\n]s", str2);

    if (strcmp(str1, str2) == 0)
    {
        printf("Chuoi str1 va str2 bang nhau\n");
    }
    else
    {
        printf("Chuoi str1 va str2 khac nhau\n");
    }

    printf("Do dai chuoi str1 la %d\n", strlen(str1));
    printf("Do dai chuoi str2 la %d\n", strlen(str2));

    strcat(str1, str2 );

    printf("Chuoi str1 sau khi noi la: %s\n", str1);

    return 0;
}