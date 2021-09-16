#include<string.h>
#include<stdio.h>

int main() {

    char str[] = "Hello, world! I'm nguyennt.dev"; // Declare the value of the string

    for (int i = 0; i < strlen(str); i++) { 
        printf("%c | ", str[i]); // Print the value of every character in the string
    }
    printf("\n"); 
    printf("%s", str); // Print the string

    char str2[] = "nguyennt.dev";
    char str3[] = "quocthinhvo.dev";

    printf("Ten thanh vien moi cua Kode: %s, ten thanh vien cu cua Kode: %s""\n", str2, str3); // Print the original str2 and str3
    strcpy(str2, str3); // Copy the value from str3 to str2 (Structure: strcpy(dest, src);)
    printf("1 month after... \n");
    printf("Ten thanh vien cu cua Kode: %s, ten thanh vien cu cua Kode: %s", str2, str3); // Print the modified str2

   return 0; 
}