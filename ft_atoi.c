/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 13:15:00 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int ft_isOverflow(const char *nptr, int isNegative, long int num, int i)
{
	long int ov_div;
	int      ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (isNegative)
		return (0);
	if (num > ov_div)
		return (1);
	if (num == ov_div)
	{
		i++;
		if (nptr[i] - '0' > ov_mod)
			return (1);
	}
	return (0);
}

int ft_isUnderflow(const char *nptr, int isNegative, long int num, int i)
{
	long int ov_div;
	int      ov_mod;

	ov_div = (-1) * (LONG_MIN / 10);
	ov_mod = (-1) * (LONG_MIN % 10);
	if (!isNegative)
		return (0);
	if (num > ov_div)
		return (1);
	if (num == ov_div)
	{
		i++;
		if (nptr[i] - '0' > ov_mod)
			return (1);
	}
	return (0);
}

int ft_digit(long int num)
{
  int count = 0;
  if (num == 0) {
    return (1);
  }
  while (num != 0) {
    count++;
    num /= 10;
  }
  return (count);
}

int	ft_atoi(const char *nptr)
{
	long int	num;
	int	        isNegative;
	int i;
	long int ov_div;

	num = 0;
	i = 0;
	isNegative = 0;
	ov_div = LONG_MAX / 10;
	//isspace関数の既定に沿った空白文字
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
	{
		i++;
	}
	while (nptr[i] == '+' || nptr[i] == '-' )
	{
		// 負の数なら、'-'カウンタを増やしてポインタを進める
		if (nptr[i] == '-')
			isNegative = 1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9' && nptr[i])
	{
		num = num * 10 + (nptr[i] - '0');
		if (ft_isOverflow(nptr, isNegative, num, i))
		{
			printf("%s\n", "overflow");
			return ((int)LONG_MAX);
		}
		if (ft_isUnderflow(nptr, isNegative, num, i))
		{
			printf("%s\n", "underflow");
			return ((int)LONG_MIN);
		}
		if (num == ov_div)
		{
			i++;
			num = num * 10 + (nptr[i] - '0');
			break;
		}
		i++;
	}
	if (isNegative)
		num = 0 - num;
	return ((int)num);
}
