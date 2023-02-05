/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoneno <hjkshn0405@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:03:51 by kyoneno           #+#    #+#             */
/*   Updated: 2023/02/05 15:00:57 by kyoneno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isNegative(const char *nptr, int i)
{
	int isNegative;
	isNegative = 0;
	while (nptr[i] == '+' || nptr[i] == '-' )
	{
		if (nptr[i] == '-')
			isNegative = 1;
	}
	return (isNegative);
}

int	ft_isOverflow(const char *nptr, int isNegative, long int num, int i)
{
	long int	ov_div;
	int			ov_mod;

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

int	ft_isUnderflow(const char *nptr, int isNegative, long int num, int i)
{
	long int	ov_div;
	int			ov_mod;

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

long	ft_add_num(const char *nptr, long int num, int i, int isNegative)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;	
	while ('0' <= nptr[i] && nptr[i] <= '9' && nptr[i])
	{
		num = num * 10 + (nptr[i] - '0');
		if (num == ov_div)
		{
			i++;
			num = num * 10 + (nptr[i] - '0');
			return (num);
		}
		if (ft_isOverflow(nptr, isNegative, num, i))
			return (LONG_MAX);
		if (ft_isUnderflow(nptr, isNegative, num, i))
			return (LONG_MIN);
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	long int	num;
	int			isNegative;
	int			i;

	num = 0;
	i = 0;
	isNegative = 0;
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	isNegative = ft_isNegative(nptr, i);
	if (isNegative)
		i++;
	num = ft_add_num(nptr, num, i, isNegative);
	if (isNegative)
		num = 0 - num;
	return ((int)num);
}
