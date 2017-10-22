#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	#ifdef FT0
	printf("%d", ft_atoi(argv[1]));
	#elif SYS0
	printf("%d", atoi(argv[1]));
	#endif
}
