#include "../main.h"

int main(int ac, char **av)
{
	char *str = "This is     some long / ** text with // many delimiters";
	char *tok;

	tok = _strtok(str, " /*");

	while (tok)
	{
		printf("%s\n", tok);
		tok = _strtok(NULL, " /*");
	}
	return (0);
}
