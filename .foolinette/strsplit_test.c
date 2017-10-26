#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return (1);
	char **res = ft_strsplit(argv[1], ' ');
	printf("[");
	int i;

	i = 0;
	while (res[i])
	{
		printf("[");
		printf("%s", res[i]);
		printf("]");
		i++;
	}
	printf("]");
	return (0);
}
