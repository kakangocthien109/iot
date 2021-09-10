#include<stdio.h>
int main() {
    /*
    - This is lab 4.2, created by nguyennt.dev
    - Date of creation: 10/09/2021
    - Date of modified: 10/09/2021
    - Goal of this project: Input and output data using scanf and printf
    */
    int a;
    scanf("%d", &a);
     a = a | 16; 
    printf("%d \n", a);
   return 0;
}