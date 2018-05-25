#include <stdio.h>

int		main()
{
	int		i = 0x000000ff;

	printf("%p\n", i);

	i = (i << 8) + i;
	printf("%p\n", i);

	return (0);
}
