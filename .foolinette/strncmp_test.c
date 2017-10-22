#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 3)
		return 1;
	int test;
	#ifdef FT0
	test = ft_strncmp(argv[1], argv[2], 10);
	printf("%d", test);
	#elif SYS0
	test = strncmp(argv[1], argv[2], 10);
	printf("%d", test);
	#endif
}
