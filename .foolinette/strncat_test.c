#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	char test[100];
	strcpy(test, "Bamboozled");
	#ifdef FT0
	ft_strncat(test, argv[1], 10);
	printf("%s", test);
	#elif SYS0
	strncat(test, argv[1], 10);
	printf("%s", test);
	#endif
}
