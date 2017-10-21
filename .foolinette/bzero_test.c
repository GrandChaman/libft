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
	ft_bzero((void*)test1, (unsigned int)5);
	#elif SYS0
	bzero((void*)test1, (unsigned int)5);
	#elif FT1
	ft_bzero((void*)test1, (unsigned int)12);
	#elif SYS1
	bzero((void*)test1, (unsigned int)12);
	#elif FT2
	ft_bzero((void*)test1, (unsigned int)0);
	#elif SYS2
	bzero((void*)test1, (unsigned int)0);
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
