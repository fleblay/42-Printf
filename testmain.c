#include <stdio.h>

int main(void)
{
	printf("'nb=%.d'\n", 42);
	printf("'nb=%.1d'\n", 42);
	printf("'nb=%.2d'\n", 42);
	printf("'nb=%.3d'\n", 42);
	printf("'nb=%8.4s'\n", "123456");
	printf("'nb=%8s'\n", "123456");
	printf("'nb=%#o'\n", 123456);
	printf("'nb=%#12x'\n", 0);
	printf("'nb=%#12x'\n", 123456);
	printf("'nb=%#12X'\n", 123456);
	printf("'nb=%#12X'\n", 123456);
	printf("'nb=%05d'\n", 42);
	printf("'nb=%-5d'\n", 42);
	printf("'nb=%0-5d'\n", 42);
	printf("'nb=%#05.2x'\n", 42);
	printf("'nb=%+d'\n", 0);
	printf("'nb=% d'\n", 0);
	printf("'nb=%+ d'\n", 0);
	printf("'nb=%--8d'\n", 12345);
	printf("'nb=%-8d'\n", 12345);
	printf("'nb=%0#8x'\n", 12345);
	printf("'nb=%-#8X'\n", 12345);
	printf("'nb=%#8X'\n", 12345);
	printf("'nb=%.s'\n", "123456");
	printf("'nb=%.0s'\n", "123456");
	printf("'nb=%.1s'\n", "123456");
	printf("%%");
	printf("\n");
	printf("ici\n");
	printf("result si chaine vide : %d", printf(""));
	//printf(NULL);
	return (0);
}
