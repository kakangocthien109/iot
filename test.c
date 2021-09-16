#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	int n;

	ch = 'a';
	n = islower(ch);

	if (n != 0)
		printf("Biến ch là chữ thường.\n");
	else
		printf("Biến ch là chữ in.\n");

	return 0;
}