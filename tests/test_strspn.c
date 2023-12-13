#include "../main.h"

int main(int ac, char **av)
{
	char *str = " * This is some text";
	int num = strspn(str, "* ");

	printf("test1: %d\n", num);
	num = _strspn(str, "* ");
	printf("test1: %d\n", num);

	num = _strspn(str, "");
	printf("test2: %d\n", num);
	num = strspn(str, "");
	printf("test2: %d\n", num);

	num = strspn(str, "***");
	printf("test3: %d\n", num);
	num = _strspn(str, "***");
	printf("test3: %d\n", num);

	num = strspn(str, "*5*");
	printf("test4: %d\n", num);
	num = _strspn(str, "*5*");
	printf("test4: %d\n", num);

	num = strspn(str, "*\0*");
	printf("test5: %d\n", num);
	num = _strspn(str, "*\0*");
	printf("test5: %d\n", num);

	num = strspn(str, " 5");
	printf("test5: %d\n", num);
	num = _strspn(str, " 5");
	printf("test5: %d\n", num);

	num = strspn(str, "5 ");
	printf("test5: %d\n", num);
	num = _strspn(str, "5 ");
	printf("test5: %d\n", num);
	return (0);
}
