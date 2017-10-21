#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	char test[25];
	unsigned long res;
	strcpy(test, "Bamboozled");
	#ifdef FT0
	res = ft_strlcat(test, argv[1], 25);
	printf("%lu => %s", res, test);
	#elif SYS0
	res = strlcat(test, argv[1], 25);
	printf("%lu => %s", res, test);
	#endif
}
