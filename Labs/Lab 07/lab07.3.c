#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
int main()
{
    int count = 0;
    for (int i = 4; i <= 100; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                printf("%d ", i);
            }
            count = 0;
        }
    }

    return 0;
}