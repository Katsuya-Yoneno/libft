/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <kyoneno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/04 21:15:07 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	ft_digit(long x)
{
	int	i;

	i = 0;
	while (x)
	{
		x /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long int	num;
	long int    LongMaxdiv;
	long int    LongMaxmod;
	int	        isNegative;
	int         mod;

	num = 0;
	LongMaxdiv = LONG_MAX / 10;
	LongMaxmod = LONG_MAX % 10;
	isNegative = 0;
	mod = 0;
	
	//isspace関数の既定に沿った空白文字
	while (('\t' <= *nptr && *nptr <= '\r') || *nptr == ' ')
	{
		nptr++;
	}
	while (*nptr == '+' || *nptr == '-' )
	{
		// 負の数なら、'-'カウンタを増やしてポインタを進める
		if (*nptr == '-')
			isNegative = 1;
		nptr++;
	}
	if (ft_strlen(nptr) > ft_digit(LONG_MAX))
		return ((int)LONG_MAX);
	while (*nptr >= '0' && *nptr <= '9')
	{
		// 上位の位から埋める
		num = num * 10 + (*nptr - '0');
		printf("num:       %ld\n", num);
		printf("LongMaxdiv:%ld\n", LongMaxdiv);
		if (num == LongMaxdiv)
		{
			printf("%s\n", "0 in");
			nptr++;
			mod = *nptr - '0';
			nptr--;
		}
		printf("mod:%d\n", mod);
		printf("LongMaxmod:%ld\n", LongMaxmod);
		printf("\n");
		printf("isNegative:%d\n", isNegative);
		if (num > LongMaxdiv && isNegative)
		{
			printf("%s\n", "1 in");
			return ((int)LONG_MIN);
		}
		if (num > LongMaxdiv && !isNegative && (mod >= LongMaxmod + 1))
		{
			printf("%s\n", "2 in");
			return ((int)LONG_MAX);
		}
		if ((num == LongMaxdiv) && (mod >= LongMaxmod + 1) && isNegative)
		{
			printf("%s\n", "3 in");
			return ((int)LONG_MIN);
		}
		if (num == LongMaxdiv && mod > LongMaxmod && !isNegative)
		{
			printf("%s\n", "4 in");
			return ((int)LONG_MAX);
		}
		nptr++;
	}
	if (isNegative)
		num = 0 - num;
	return (num);
}


// intの範囲を超えた引数が与えられた際の挙動は定義されていない
// int main(void){
// 	printf("my: %d\n", ft_atoi("9223372036854775808"));
// 	printf("te: %d\n", atoi("9223372036854775808"));
// 	printf("my: %d\n", ft_atoi("-9223372036854775809"));
// 	printf("te: %d\n", atoi("-9223372036854775809"));
// 	printf("my: %d\n", ft_atoi("18446744073709551616"));
// 	printf("te: %d\n", atoi("18446744073709551616"));
// 	printf("my: %d\n", ft_atoi("18446744073709551616"));
// 	printf("te: %d\n", atoi("18446744073709551616"));
// 	printf("my: %d\n", ft_atoi("18446744073709551614"));
// 	printf("te: %d\n", atoi("18446744073709551614"));
// 	printf("my: %d\n", ft_atoi("18446744073709551614"));
// 	printf("te: %d\n", atoi("18446744073709551614"));
// 	return 0;
// }