#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0x11111111;
	j = 0x01010101;
	k = 0x10101010;
	l = 0x00000000;

/*
	int result = i & j;
	printf("%d\n", result);
	printf("and operator:\n");
	printf("print int: %d\n", result);
	printf("print hex: %p\n", result);

	result = j | k;
	printf("printf int : %d\n", result);
	printf("print hex: %p\n", result);	
	

	result = j ^ k;
	printf("printf int : %d\n", result);
	printf("print hex: %p\n", result);	

	result = i | j;
	printf("printf int : %d\n", result);
	printf("print hex: %p\n", result);	

	result = i ^ j;
	printf("printf int : %d\n", result);
	printf("print hex: %p\n", result);	
*/

	int x = 2147483647;

	int a = 0;
	int	y;
	printf("this is y = x << a\n\n");
	while (a < 10)
	{
		y = x << a;
		printf("%p\n", y);
		a++;
	}

	printf("\n\n\n\n\n");
	a = 0;
	int z;
	printf("this is z = x << a\n\n");
	while (a < 10)
	{
		z = x << a;
		printf("%p\n", z);
		a++;
	}
	return (0);
}
