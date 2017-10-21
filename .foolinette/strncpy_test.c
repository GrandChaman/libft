#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printnull(char c)
{
	if (!c)
		printf("0");
}

int main(int argc, const char **argv)
{
	if (argc != 3)
		return 1;
	char test[15];
	memset(test, 'x', 15);
	#ifdef FT0
	ft_strncpy(test, argv[1], atoi(argv[2]));
	for(int i = 0; i < 15; i++)
	{
		printf("%c", test[i]);
		printnull(test[i]);
	}
	#elif SYS0
	strncpy(test, argv[1], atoi(argv[2]));
	for(int i = 0; i < 15; i++)
	{
		printf("%c", test[i]);
		printnull(test[i]);
	}
	#endif
}
