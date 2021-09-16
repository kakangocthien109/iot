#include<stdio.h>
int main() {
    /*
    - This is lab 2.3, created by nguyennt.dev
    - Date of creation: 10/09/2021
    - Date of modified: 10/09/2021
    - Goal of this project: Input and output data using scanf and printf
    */
   enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };
   enum Company microsoft = MICROSOFT, facebook = FACEBOOK, xerox = XEROX, yahoo = YAHOO, ebay = EBAY, google = GOOGLE;
   printf("The value of google is: %d\n", google);
   printf("The value of facebook is: %d\n", facebook);
   printf("The value of xerox is: %d\n", xerox);
   printf("The value of yahoo is: %d\n", yahoo);
   printf("The value of ebay is: %d\n", ebay);
   printf("The value of microsoft is: %d\n", microsoft);
   return 0;
}