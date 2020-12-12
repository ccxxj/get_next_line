#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;
	str = "\0";
	str = (char *)malloc(1);
	if (!str)
		printf("empty");
	else
	{
		printf("not empty");
	}
	free(str);
	return (0);
}