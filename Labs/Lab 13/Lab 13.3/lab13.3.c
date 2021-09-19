#include <stdio.h>
#include <stdlib.h>
#define max 10000

int main() {
    FILE *fr = fopen("test.txt", "r");
    char data[max];
    int count = 0;

    if (fr != NULL)
    {
        while (fgets(data, max, fr) != NULL)
        {
            count++;
            // printf("%s", data);
        }    
    }
    printf("Tong so dong la: %d", count);

    fclose(fr);
    fr = NULL;

    return 0;
}