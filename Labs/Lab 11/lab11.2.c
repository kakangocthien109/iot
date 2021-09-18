#include <stdio.h>
#include <stdbool.h>

char str1[] = "nguyennt.dev";
char str2[] = "nguyennt";

bool compare()
{

    char *pnt1 = str1;
    char *pnt2 = str2;

    int i = 0;

    bool isEquals = false;

    while (*(pnt1 + i) == *(pnt2 + i) && *(pnt1 + i) != '\0' && *(pnt2 + i) != '\0')
    {
        ++i;
    }

    if (*(pnt1 + i) == '\0' && *(pnt2 + i) == '\0')
        isEquals = true;
    else
        isEquals = false;

    return isEquals;
}

int main()
{
    printf("\n%d\n", compare(str1, str2));
    return 0;
}