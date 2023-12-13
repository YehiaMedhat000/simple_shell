#include "../main.h"

int main(int ac, char **av)
{
	char *str = " * This is some text";
	int num = strcspn(str, "* ");

	printf("test1: %d\n", num);
	num = _strcspn(str, "* ");
	printf("test1: %d\n", num);

	num = _strcspn(str, "");
	printf("test2: %d\n", num);
	num = strcspn(str, "");
	printf("test2: %d\n", num);

	num = strcspn(str, "***");
	printf("test3: %d\n", num);
	num = _strcspn(str, "***");
	printf("test3: %d\n", num);

	num = strcspn(str, "*5*");
	printf("test4: %d\n", num);
	num = _strcspn(str, "*5*");
	printf("test4: %d\n", num);

	num = strcspn(str, "*\0*");
	printf("test5: %d\n", num);
	num = _strcspn(str, "*\0*");
	printf("test5: %d\n", num);

	num = strcspn(str, " 5");
	printf("test5: %d\n", num);
	num = _strcspn(str, " 5");
	printf("test5: %d\n", num);

	num = strcspn(str, "5 ");
	printf("test5: %d\n", num);
	num = _strcspn(str, "5 ");
	printf("test5: %d\n", num);
	return (0);
}
