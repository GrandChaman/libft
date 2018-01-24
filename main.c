
#include "libft.h"
#include <unistd.h>

int main(void)
{
	ft_printf("m%#.9od\nee", 123456789);
	sleep(1);
	write(1, "\n\n", 2);
	printf("m%#.9od\nee", 123456789);
	return (0);
}
