#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 4)
		return 1;
	char test[strlen(argv[1])];
	unsigned long res;
	strcpy(test, argv[1]);
	#ifdef FT0
	res = ft_strlcat(test, argv[2], atoi(argv[3]));
	printf("%lu => %s", res, test);
	#elif SYS0
	res = strlcat(test, argv[2], atoi(argv[3]));
	printf("%lu => %s", res, test);
	#endif
}
