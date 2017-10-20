#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	char test[100];
	#ifdef FT0
	ft_strcpy(test, argv[1]);
	printf("%s", test);
	#elif SYS0
	strcpy(test, argv[1]);
	printf("%s", test);
	#endif
}
