#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
	if (argc != 2)
		return 1;
	char *test;
	char *test1;
	if (!(test = (char*)malloc(sizeof(char) * 15)))
		exit(1);
	strcpy(test, "Bamboozled");
	#ifdef FT0
	test1 = ft_strrchr(test, argv[1][0]);
	printf("%s", test1 == NULL ? "NULL" : test1);
	#elif SYS0
	test1 = strrchr(test, argv[1][0]);
	printf("%s", test1 == NULL ? "NULL" : test1);
	#endif
	free(test);
}
