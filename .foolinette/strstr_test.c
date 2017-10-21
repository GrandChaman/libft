#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 3)
		return 1;
	char *test;
	#ifdef FT0
	test = ft_strstr(argv[1], argv[2]);
	printf("%s", test == NULL ? "NULL" : test);
	#elif SYS0
	test = strstr(argv[1], argv[2]);
	printf("%s", test == NULL ? "NULL" : test);
	#endif
}
