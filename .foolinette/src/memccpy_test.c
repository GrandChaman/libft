#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *test1;
	void *tmp;
	void *tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if(!(test1 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	bzero(test1, 12);
	#ifdef FT0
	ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)12);
	#elif SYS0
	memccpy(test1, "Hello Woxld", 'x', (unsigned int)12);
	#elif FT1
	ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)5);
	#elif SYS1
	memccpy(test1, "Hello Woxld", 'x', (unsigned int)5);
	#elif FT2
	ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)0);
	#elif SYS2
	memccpy(test1, "Hello Woxld", 'x', (unsigned int)0);
	#elif FT3
	ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)9);
	#elif SYS3
	memccpy(test1, "Hello Woxld", 'x', (unsigned int)9);
	#elif FT4
	tmp = ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)10);
	tmp2 = memccpy(test1, "Hello Woxld", 'x', (unsigned int)10);
	if(tmp == tmp2)
	{
		printf("OK");
		exit(0);
	}
	else
	{
		printf("KO");
		exit(1);
	}
	#elif FT5
	tmp = ft_memccpy(test1, "Hello Woxld", 'x', (unsigned int)5);
	tmp2 = memccpy(test1, "Hello Woxld", 'x', (unsigned int)5);
	if(tmp == tmp2)
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
