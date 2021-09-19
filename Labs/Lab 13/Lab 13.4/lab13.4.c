#include <stdio.h>
#include <stdlib.h>
#define max 10000

int main()
{
    FILE *fr1 = fopen("test.txt", "r");
    FILE *fr2 = fopen("test2.txt", "r");
    FILE *fw = fopen("test3.txt", "w");

    char data[max];

    if (fr1 != NULL && fr2 != NULL)
    {
        while (fgets(data, max, fr1) != NULL)
        {
            fputs(data, fw);
        }
        fputs("\n", fw);
        while (fgets(data, max, fr2) != NULL)
        {
            fputs(data, fw);
        }
    }

    fclose(fr1);
    fclose(fr2);
    fclose(fw);
    fr1 = NULL;
    fr2 = NULL;
    fw = NULL;
    return 0;
}