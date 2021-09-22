#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char data[1024];
    int i = 0;
    printf("Xin vui long nhap chuoi ky tu:\n");
    scanf("%[^\n]s", data);

    for (i = 0; i < strlen(data); i++)
    {
        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = tolower(data[i]);
            continue;
        }
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = toupper(data[i]);
        }
    }

    printf("Chuoi ky tu sau khi chuyen doi la:\n");
    printf("%s", data);

    return 0;
}