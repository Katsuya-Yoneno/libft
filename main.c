#include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>

char func(unsigned int i, char c){
	return (c + i);
}

char	*test_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	count_t;
	size_t	search;

	count = 0;
	count_t = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (count < len && haystack[count])
	{
		if (haystack[count] == needle[count_t])
		{
			search = count;
			while (search < len && haystack[search] == needle[count_t])
			{
				search++;
				count_t++;
				if (needle[count_t] == '\0')
					return ((char *)haystack + count);
			}
			count_t = 0;
		}
		count++;
	}
	return (0);
}

int main(void){
	char *str = "libft-test-tokyo";
	int	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		printf("ft_strnstr(%s, "", %d)my_ft:%s\n", str, i , ft_strnstr(str, "", i));
		printf("ft_strnstr(%s, "", %d)test:%s\n", str, i , test_strnstr(str, "", i));
		printf("\n");
		printf("ft_strnstr(%s, libft-test-tokyo, %d)my_ft:%s\n", str, i , ft_strnstr(str, "libft-test-tokyo", i));
		printf("ft_strnstr(%s, libft-test-tokyo, %d)test:%s\n", str, i , test_strnstr(str, "libft-test-tokyo", i));
		printf("\n");
		printf("ft_strnstr(%s, libft, %d)my_ft:%s\n", str, i , ft_strnstr(str, "libft", i));
		printf("ft_strnstr(%s, libft, %d)test:%s\n", str, i , test_strnstr(str, "libft", i));
		printf("\n");
		printf("ft_strnstr(%s, test, %d)my_ft:%s\n", str, i , ft_strnstr(str, "test", i));
		printf("ft_strnstr(%s, test, %d)test:%s\n", str, i , test_strnstr(str, "test", i));
		printf("\n");
		printf("ft_strnstr(%s, tokyo, %d)my_ft:%s\n", str, i , ft_strnstr(str, "tokyo", i));
		printf("ft_strnstr(%s, tokyo, %d)test:%s\n", str, i , test_strnstr(str, "tokyo", i));
		printf("\n");
		printf("ft_strnstr(%s, libft~, %d)my_ft:%s\n", str, i , ft_strnstr(str, "libft~", i));
		printf("ft_strnstr(%s, libft~, %d)test:%s\n", str, i , test_strnstr(str, "libft~", i));
		printf("\n");
		printf("ft_strnstr(%s, z, %d)my_ft:%s\n", str, i , ft_strnstr(str, "z", i));
		printf("ft_strnstr(%s, z, %d)test:%s\n", str, i , test_strnstr(str, "z", i));
		printf("\n");
	}
	return 0;
}