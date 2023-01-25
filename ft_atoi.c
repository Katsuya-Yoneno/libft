/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/01/25 17:47:42 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	num;
	int	counter;

	num = 0;
	counter = 0;
	//isspace関数の既定に沿った空白文字
	while (('\t' <= *nptr && *nptr <= '\r') || *nptr == ' ')
	{
		nptr++;
	}
	while (*nptr == '+' || *nptr == '-' )
	{
		// 負の数なら、'-'カウンタを増やしてポインタを進める
		if (*nptr == '-')
			counter++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		// 上位の位から埋める
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	//'-'が奇数個なら負の数として判定
	if (counter % 2 == 1)
		num = 0 - num;
	return (num);
}


//intの範囲を超えた引数が与えられた際の挙動は定義されていない
int main(void){
	printf("my: %d\n", ft_atoi("9223372036854775808"));
	printf("te: %d\n", atoi("9223372036854775808"));
	printf("my: %d\n", ft_atoi("-9223372036854775809"));
	printf("te: %d\n", atoi("-9223372036854775809"));
	printf("my: %d\n", ft_atoi("18446744073709551616"));
	printf("te: %d\n", atoi("18446744073709551616"));
	printf("my: %d\n", ft_atoi("18446744073709551616"));
	printf("te: %d\n", atoi("18446744073709551616"));
	printf("my: %d\n", ft_atoi("18446744073709551614"));
	printf("te: %d\n", atoi("18446744073709551614"));
	printf("my: %d\n", ft_atoi("18446744073709551614"));
	printf("te: %d\n", atoi("18446744073709551614"));
	return 0;
}