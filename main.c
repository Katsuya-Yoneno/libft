#include "libft.h"

int main (void)
{
	char *s = "diddidd";
	char c = 'i';
	char **res = ft_split(s, c);
	int i = 0;
	while (res)
	{
		printf("%s, ", res[i]);
		i++;
	}
	return 0;
}