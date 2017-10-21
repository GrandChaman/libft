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
	bzero(test1, 12);
	#ifdef FT0
	ft_memcpy(test1, "Hello World", (unsigned int)12);
	#elif SYS0
	memcpy(test1, "Hello World", (unsigned int)12);
	#elif FT1
	ft_memcpy(test1, "Hello World", (unsigned int)5);
	#elif SYS1
	memcpy(test1, "Hello World", (unsigned int)5);
	#elif FT2
	ft_memcpy(test1, "Hello World", (unsigned int)0);
	#elif SYS2
	memcpy(test1, "Hello World", (unsigned int)0);
	#elif FT3
	tmp = ft_memcpy(test1, "Hello World", (unsigned int)10);
	test1 = memcpy(test1, "Hello World", (unsigned int)10);
	if(tmp == test1)
	{
		printf("OK");
		exit(0);
	}
	else
	{
		printf("KO");
		exit(1);
	}
	#endif
	for(int i = 0; i < 12; i++)
	{
		if (test1[i] == '\0')
			printf("0");
		else if (test1[i] > 31)
			printf("%c", test1[i]);
	}
	free(test1);
}
