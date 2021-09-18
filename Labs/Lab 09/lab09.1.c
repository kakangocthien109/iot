#include <stdio.h>

char ho[10] = "Nguyen";
char ten[10] = "Thien";

void string_length()
{
    int i = 0, j = 0;
    while (ho[i] != '\0')
    {
        i++;
    }
    printf("Do dai cua chuoi 'ho' la: %d\n", i);
    
    while (ten[j] != '\0') {
        j ++;
    }
    printf("Do dai cua chuoi 'ten' la: %d\n", j);
}

int main() {
    string_length();
    return 0;
}