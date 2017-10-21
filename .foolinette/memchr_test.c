#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *test1;
	char *tmp;

	if(!(test1 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	strcpy(test1, "Hello World");

	#ifdef FT0
	tmp = ft_memchr(test1, 'W', 12);
	#elif SYS0
	tmp = memchr(test1, 'W', 12);
	#elif FT1
	tmp = ft_memchr(test1, 'W', 5);
	#elif SYS1
	tmp = memchr(test1, 'W', 5);
	#elif FT2
	tmp = ft_memchr(test1, 'B', 12);
	#elif SYS2
	tmp = memchr(test1, 'B', 12);
	#endif
	if (tmp)
		printf("%s", tmp);
	else
		printf("NULL");
	free(test1);
}
