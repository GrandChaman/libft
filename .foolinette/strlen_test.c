#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	#ifdef FT0
	printf("%lu", ft_strlen(argv[1]));
	#elif SYS0
	printf("%lu", strlen(argv[1]));
	#endif
}
