#include <stdio.h>
#include <string.h>

int main()
{
    float a, b;
    printf("Xin vui long nhap 2 so a, b\n");
    scanf("%f %f", &a, &b);
    
    if ((a != (int)a) || (b != (int)b))
    {
        printf ("So nhap vao khong phai so nguyen\n");
    }

    else {
        printf ("So nhap vao la so nguyen \n");
    
     if ((a - b) == 0)
    {
        printf ("Hai so a, b bang nhau\n");
    }

    
    else if ((a - b) > 0)
    {
        printf ("So a lon hon so b\n");
    }

    
    else if ((a - b) < 0)
    {
        printf ("So a be hon so b \n");
    }

    }

    getchar();
    return 0;
}