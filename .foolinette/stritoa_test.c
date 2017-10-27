#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	printf("%s", ft_itoa(atoi(argv[1])));
}
