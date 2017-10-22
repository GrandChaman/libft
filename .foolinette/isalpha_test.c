#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i;

	i = -1;
	while (i < 500)
	{
		if (ft_isalpha(i) != isalpha(i))
		{
			printf("KO : %d != %d with i = %d", ft_isalpha(i), isalpha(i), i);
			return (1);
		}
		i++;
	}
	printf("OK");
	return (0);
}
