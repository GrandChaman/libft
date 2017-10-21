#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *test1;
	void *tmp;

	tmp = NULL;
	if(!(test1 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	strcpy(test1, "Hello World");

	#ifdef FT0
	test1 = ft_memset((void*)test1, (int)'A', (unsigned int)5);
	#elif SYS0
	test1 = memset((void*)test1, (int)'A', (unsigned int)5);
	#elif FT1
	test1 = ft_memset((void*)test1, (int)'A', (unsigned int)12);
	#elif SYS1
	test1 = memset((void*)test1, (int)'A', (unsigned int)12);
	#elif FT2
	test1 = ft_memset((void*)test1, (int)'B', (unsigned int)0);
	#elif SYS2
	test1 = memset((void*)test1, (int)'B', (unsigned int)0);
	#elif FT3
	tmp = ft_memset((void*)test1, (int)'B', (unsigned int)0);
	test1 = memset((void*)test1, (int)'B', (unsigned int)0);
	if (tmp == test1)
	{
		printf("OK");
		exit(0);
	}
	else
	{
		printf("KO");
		exit(1);
	}
	exit(0);
	#endif
	printf("%s", test1);
	free(test1);
}
