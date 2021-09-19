#include <stdio.h>
int main()
{
    FILE *fw = fopen("test.txt", "w");
    char data[100];

    printf("\n Xin vui long nhap thong tin\n");

    // char temp;
    // scanf("%c", &temp); // temp statement to clear buffer
    scanf("%[^\n]s", data);

    fprintf(fw, "%s", data);

    fclose(fw);
    fw = NULL;  

    return 0;
}