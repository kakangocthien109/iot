#include <stdio.h>
#include <stdlib.h>
#define max 10000

int main()
{
    FILE *fr = fopen("test.txt", "r");
    char data[max];

    if (fr != NULL)
    {
        while (fgets(data, max, fr) != NULL)
        {
            printf("%s", data);
        }    
    }
    fclose(fr);
    fr = NULL;

    return 0;
}