#include <stdio.h>

int		main()
{
	int		i;

	i = -65036;

	char	c;
	
	c = (char)i;
	
	printf("%d\n", i % 256);
	printf("%c\n", c);
	return (0);
}
