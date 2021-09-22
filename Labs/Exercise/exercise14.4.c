#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *info;

    time (&rawtime);

    info = localtime(&rawtime);
    printf("The local time and local date now is %s", asctime(info));

    return 0;
}