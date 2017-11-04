#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 3)
		return 1;
	int res = ft_atoi_base(argv[1], argv[2]);
	printf("%d", res);
	return (0);
}
