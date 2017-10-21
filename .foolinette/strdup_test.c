#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	char *nstr;

	if (argc != 2)
		return 1;
	#ifdef FT0
	nstr = ft_strdup(argv[1]);
	if (nstr == argv[1])
		exit(1);
	printf("%s", nstr);
	#elif SYS0
	nstr = strdup(argv[1]);
	if (nstr == argv[1])
		exit(1);
	printf("%s", nstr);
	#endif
}
