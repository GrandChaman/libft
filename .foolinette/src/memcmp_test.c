#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *test1;
	char *test2;
	int tmp;

	if(!(test1 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	if(!(test2 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	strcpy(test1, "Hello World");
	memset(test2, 'x', 12);
	memcpy(test2, "Hello", 5);
	#ifdef FT0
	tmp = ft_memcmp(test1, test2, 12);
	#elif SYS0
	tmp = memcmp(test1, test2, 12);
	#elif FT1
	tmp = ft_memcmp(test1, test2, 5);
	#elif SYS1
	tmp = memcmp(test1, test2, 5);
	#elif FT2
	tmp = ft_memcmp(test1, test2, 0);
	#elif SYS2
	tmp = memcmp(test1, test2, 0);
	#elif FT3
	tmp = ft_memcmp(test1, test2, 3);
	#elif SYS3
	tmp = memcmp(test1, test2, 3);
	#endif
	printf("%d", tmp);
	free(test1);
	free(test2);
}
