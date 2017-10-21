#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *test1;
	char test2[100];
	void *tmp;
	unsigned int len;

	tmp = NULL;
	if(!(test1 = (char*)malloc(sizeof(char) * 12)))
		exit(10);
	memset(test2, 'x', 100);
	memset(test1, 'x', 12);
	strcpy(test2, "Hello World");
	#ifdef FT0
	len = 12;
	ft_memmove(test1, test2, len);
	#elif SYS0
	len = 12;
	memmove(test1, test2, len);
	#elif FT1
	len = 5;
	ft_memmove(test1, test2, len);
	#elif SYS1
	len = 5;
	memmove(test1, test2, len);
	#elif FT2
	len = 5;
	strcpy(test1, "Hello World");
	ft_memmove(test1, test1 + 1, len); //DEST < SRC
	#elif SYS2
	len = 5;
	strcpy(test1, "Hello World");
	memmove(test1, test1 + 1, len); //DEST < SRC
	#elif FT3
	len = 5;
	strcpy(test1, "Hello World");
	ft_memmove(test1, test1, len); //DEST == SRC
	#elif SYS3
	len = 5;
	strcpy(test1, "Hello World");
	memmove(test1, test1, len); //DEST == SRC
	#elif FT4
	len = 5;
	strcpy(test1, "Hello World");
	ft_memmove(test1 + 1, test1, len); //DEST >SRC
	#elif SYS4
	len = 5;
	strcpy(test1, "Hello World");
	memmove(test1 + 1, test1, len); //DEST > SRC
	#elif FT5
	len = 5;
	strcpy(test1, "Hello World");
	tmp = ft_memmove(test1 + 1, test1, len);
	test1 = ft_memmove(test1 + 1, test1, len);
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
