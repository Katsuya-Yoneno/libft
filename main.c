#include "libft.h"

int main (void)
{
	void *test;
	//LONG_MIN+1
	test = ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
	free(test);
	return 0;
}